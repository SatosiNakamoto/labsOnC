#include <iostream>

template<class T>
class UniquePtr
{
public:
    UniquePtr(T* input) : ptr(input) {}
    UniquePtr(const UniquePtr& input) = delete;
    UniquePtr& operator = (const UniquePtr& input) = delete;
    explicit UniquePtr(UniquePtr&& input);
    UniquePtr& operator = (UniquePtr&& input);
    T operator * () const;
    T* operator -> () const;
    T* get() const;
    T* release();
    void reset(T* input = nullptr);
    ~UniquePtr();
private:
    T* ptr = nullptr;
};

template<class T>
UniquePtr<T>::UniquePtr(UniquePtr&& input)
{
    ptr = input.ptr;
    input.ptr = nullptr;
}

template<class T>
UniquePtr<T>& UniquePtr<T>::operator = (UniquePtr&& input)
{
    if (this != &input)
    {
        delete ptr;
        ptr = input.ptr;
        input.ptr = nullptr;
    }
    return *this;
}

template<class T>
T UniquePtr<T>::operator * () const
{
    return *ptr;
}

template<class T>
T* UniquePtr<T>::operator -> () const
{
    return ptr;
}

template<class T>
T* UniquePtr<T>::get() const
{
    return ptr;
}

template<class T>
T* UniquePtr<T>::release()
{
    T* tmp = ptr;
    ptr = nullptr;
    return tmp;
}

template<class T>
void UniquePtr<T>::reset(T* pointer)
{
    delete ptr;
    ptr = pointer;
}

template<class T>
UniquePtr<T>::~UniquePtr()
{
    delete ptr;
}