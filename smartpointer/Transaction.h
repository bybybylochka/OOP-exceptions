#pragma once
#include<iostream>
template<class T>
class Transaction
{
	T* previous;
	T* current;
public:
	Transaction();
	Transaction(const Transaction& Obj);
	~Transaction();
	void begin_transaction();
	void commit_transaction();
	void delete_transaction();
	Transaction<T>& operator=(const Transaction& obj);
	T* operator->();
	T& operator*();
};


template<class T>
Transaction<T>::Transaction()
{
	this->previous = NULL;
	this->current = new T;
}

template<class T>
Transaction<T>::Transaction(const Transaction& obj)
{
	this->previous = NULL;
	this->current = new T(*(obj->current));
}

template<class T>
Transaction<T>::~Transaction()
{
	delete this->previous;
	delete this->current;
}

template<class T>
void Transaction<T>::begin_transaction()
{
	delete this->previous;
	this->previous = this->current;
	this->current = new T(*(this->previous));
	if (this->current)
		this->current->create_data();
}

template<class T>
void Transaction<T>::commit_transaction()
{
	delete this->previous;
	this->previous = NULL;
}

template<class T>
void Transaction<T>::delete_transaction()
{
	if (this->previous != NULL)
	{
		delete this->current;
		this->current = this->previous;
		this->previous = NULL;
	}
}

template<class T>
Transaction<T>& Transaction<T>::operator=(const Transaction& obj)
{
	if (this != &obj)
	{
		delete this->current;
		this->current = new T(*(obj->current));
	}
	return *this;
}

template<class T>
T* Transaction<T>::operator->()
{
	return this->current;
}


template<class T>
T& Transaction<T>::operator*()
{
	return *current;
}