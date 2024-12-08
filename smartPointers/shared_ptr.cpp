#include <iostream>

template <typename T>
class Shared_ptr {
public:
    Shared_ptr(T* ptr = nullptr) : m_ptr(ptr), m_count(new int(1)) {}

    //Coppy constroctor//
    Shared_ptr(const Shared_ptr<T>& cp) : m_ptr(cp.m_ptr), m_count(cp.m_count) {
        ++(*m_count);
    }

    //Move constructor//
    Shared_ptr(Shared_ptr<T>&& mv) noexcept : m_ptr(mv.m_ptr), m_count(mv.m_count) {
        mv.m_ptr = nullptr;
        mv.m_count = nullptr;
    }

    //Copy assignment operator//
    Shared_ptr<T>& operator=(const Shared_ptr<T>& coAs) {
        if(this != &coAs) {
            release();
            m_ptr = coAs.m_ptr;
            m_count = coAs.m_count;
            if(m_count) {
                ++(*m_count);
            }
        }
        return *this;
    }

    //Move assignment operator//
    Shared_ptr<T>& operator=(Shared_ptr<T>&& mvAs) noexcept {
        if(this != &mvAs) {
            release();
            m_ptr = mvAs.m_ptr;
            m_count = mvAs.m_count;
            mvAs.m_ptr = nullptr;
            mvAs.m_count = nullptr;
        }
        return *this;
    }

        T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

    T* get() const {
        return m_ptr;
    }

    int use_count() const {
        return *m_count;
    }

    bool unique() const {
        return *m_count == 1;
    }

    ~Shared_ptr() {
        release();
    }

private:
    void release() {
        if(m_ptr && --(*m_count) == 0) {
            delete m_ptr;
            delete m_count;
        }
    }
    T* m_ptr;
    int* m_count;
};


int main() {

    Shared_ptr<int> p1(new int(10));
    std::cout << "p1 use_count is: " << p1.use_count() << std::endl;

    Shared_ptr<int> p2 = p1;
    std::cout << "p2 use_count is: " << p2.use_count() << std::endl;

    Shared_ptr<int> p3;
    p3 = p2;
    std::cout << "p3 use_count is: " << p3.use_count() << std::endl;

    Shared_ptr<int> p4 = std::move(p1);
    std::cout << "p4 use_count is: " << p4.use_count() << std::endl;

    Shared_ptr<int> p5(new int(10));
    std::cout << "p5 use_count is: " << p5.use_count() << std::endl;
    
    Shared_ptr<int> p6;
    p6 = std::move(p5);
    std::cout << "p6 use_count is: " << p6.use_count() << std::endl;
    return 0;
}