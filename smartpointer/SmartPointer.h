#pragma once
#include<iostream>
template <class T>
struct Status {
	T* ptr;
	int counter;
};
template<class T>
class SmartPointer
{
	Status<T>* pointer;
public:
	SmartPointer(T* ptr);
	~SmartPointer();
	SmartPointer(const SmartPointer& obj);
	SmartPointer& operator=(const SmartPointer& smart_pointer);
	T* operator->();
	SmartPointer& operator+(const SmartPointer& smart_pointer);
};

template<class T>
SmartPointer<T>::SmartPointer(T* ptr)
{
	if (!ptr)
		pointer = NULL;
	else
	{
		pointer = new Status<T>();
		pointer->ptr = ptr;
		pointer->counter = 1;
	}
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
	if (pointer)
	{
		pointer->counter--;
		if (pointer->counter == 0)
		{
			delete pointer->ptr;
			delete pointer;
		}
	}
}

template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj)
{
	pointer = obj.pointer;
	if (pointer != NULL)
	{
		pointer->counter++;
	}
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& smart_pointer)
{
	if (pointer)
	{
		pointer->counter--;
		if (pointer->counter == 0)
		{
			delete pointer->ptr;
			delete pointer;
		}
	}
	pointer = smart_pointer.pointer;
	if (pointer)
		pointer->counter++;
	return *this;
}

template<class T>
T* SmartPointer<T>::operator->()
{
	if (pointer)
		return pointer->ptr;
	else return NULL;
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator+(const SmartPointer& smart_pointer1)
{
	SmartPointer<T> smart_pointer;
	smart_pointer.pointer->counter = smart_pointer1.pointer->counter + this->pointer->counter;
	return smart_pointer;
}