#include <iostream>

template <typename T>
class Auto_ptr {
public:
    explicit Auto_ptr(T* ptr = nullptr) : m_ptr(ptr) {}
    
    Auto_ptr(Auto_ptr& other) : m_ptr(other.m_ptr) {
        other.m_ptr = nullptr;
    }
    
    Auto_ptr& operator=(Auto_ptr& other) {
        if(this != &other) {
            delete m_ptr;
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }
    
    T& operator*() {
        return  *m_ptr;
    }

    T* operator->() {
        return m_ptr;
    }

    T* get() const {
        return m_ptr;
    }
    
    ~Auto_ptr() {
        delete m_ptr;
    }

private:
    T* m_ptr;
};

class Test {
public:
    int x = 10;
    void print() {
        std::cout << "x = " << x << std::endl;
    }
};

int main() {

    Auto_ptr<Test> test1(new Test());
    test1->print();

    Auto_ptr<Test> test2(test1);
    test2->print();
    if (test1.get() == nullptr) {
        std::cout << "ptr1 is null after transfer." << std::endl;
    }
    
    Auto_ptr<Test> test3(new Test());
    Auto_ptr<Test> test4(new Test());
    test3 = test4;
    test3->print();
    
    if(test4.get() == nullptr) {
        std::cout << "ptr1 is null after transfer." << std::endl;
    }

    return 0;
}