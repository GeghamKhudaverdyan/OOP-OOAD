#include <iostream>

template <typename T>
class Unique_ptr {
public:
    explicit Unique_ptr(T* ptr = nullptr) : m_ptr(ptr) {}

    Unique_ptr(Unique_ptr&& oth) noexcept : m_ptr(oth.m_ptr) {
        oth.m_ptr = nullptr;
    }

    Unique_ptr& operator=(Unique_ptr&& oth) noexcept {
        if(this != &oth) {
            delete m_ptr;
            m_ptr = oth.m_ptr;
            oth.m_ptr = nullptr;
        }
        return *this;
    }

    Unique_ptr(Unique_ptr&) = delete;
    Unique_ptr& operator=(const Unique_ptr&) = delete;

    T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

    T* get() const {
        return m_ptr;
    }

    T* release() {
        T* ptr = m_ptr;
        m_ptr = nullptr;
        return ptr;
    }

    void reset(T* ptr = nullptr) {
        delete m_ptr;
        m_ptr = ptr;
    }

    ~Unique_ptr() {
        delete m_ptr;
    }

private:
    T* m_ptr;
};

class Test {
public:
    void print() {
        std::cout << "hello" << std::endl;
    }
};

int main() {

    Unique_ptr<Test> test1(new Test());
    Test* ptr = test1.release();

    if(test1.get() == nullptr) {
        std::cout << "hi" << std::endl;
    }

    Unique_ptr<Test> test2 = std::move(test1);
    if (test1.get() == nullptr) {
        std::cout << "ptr1 is now null after move.\n";
    }
    test2->print();

    Unique_ptr<Test> test3;
    test3 = std::move(test2);
    if (test2.get() == nullptr) {
        std::cout << "ptr2 is now null after move assignment.\n";
    }

    test3->print();
    test3.reset(new Test());
    test3->print();

    return 0;
}