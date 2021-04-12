#ifndef _SAHRED_
#define _SAHRED_

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* point) : ptr(point), reference_count(1) {}
	SharedPtr(const SharedPtr& input);
	T* operator -> () const;
	T operator * () const;
	T* get() const;
	unsigned int getRefCount() const;
	void reset(T* ptr = nullptr);
	~SharedPtr();

private:
	T* ptr;
	unsigned int reference_count;
};


template<typename T>
SharedPtr<T>::~SharedPtr()
{
    (reference_count)--;
    if (reference_count == 0) 
    {
        delete ptr;
    }
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& input)
{
    ptr = input.ptr;
    reference_count = input.reference_count;
    (reference_count)++;
}

template<typename T>
T SharedPtr<T>::operator * () const
{
    return *ptr;
}

template<typename T>
T* SharedPtr<T>::operator -> () const
{
    return ptr;
}

template<typename T>
T* SharedPtr<T>::get() const
{
    return ptr;
}

template<typename T>
unsigned int SharedPtr<T>::getRefCount() const
{
    return reference_count;
}

template<typename T>
void SharedPtr<T>::reset(T* pointer)
{
    (reference_count)--;
    if (reference_count == 0)
    {
        delete ptr;
    }  

    if (ptr) 
    {
        ptr = pointer;
        reference_count = 1;
    }
}

#endif