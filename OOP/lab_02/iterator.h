#pragma once

#include "iteratorbase.h"
#include "listitem.h"

//#include <memory>

template <typename T>
class Iterator : public IteratorBase<T>
{
protected:
	std::weak_ptr<ListItem<T>> current_ptr;

public:
    Iterator(std::shared_ptr<ListItem<T>> &);

	~Iterator();

	Iterator<T>& operator= (const Iterator<T>&);

	void next();
	void prev();

	void advance(int);
	void distance(int);

	T& operator* () const;

	Iterator<T>& operator++ ();
	Iterator<T> operator++ (int);
	Iterator<T>& operator-- ();
	Iterator<T> operator-- (int);

	Iterator<T>& operator+= (int);
	Iterator<T>& operator-= (int);

	bool operator== (const Iterator<T>&) const;
	bool operator!= (const Iterator<T>&) const;
};



// sourse



template<typename T>
Iterator<T>::Iterator(std::shared_ptr<ListItem<T>>& ptr)
{
	current_ptr = ptr;
}


template<typename T>
Iterator<T>::~Iterator()
{
	current_ptr.reset();
}


template<typename T>
Iterator<T>& Iterator<T>::operator= (const Iterator<T>& iter)
{
	return Iterator<T>(iter);
}


template<typename T>
void Iterator<T>::next()
{
	auto item = current_ptr.lock();
	item = item->next;
	current_ptr = item;
}

template<typename T>
void Iterator<T>::prev()
{
	auto item = current_ptr.lock();
	item = item->prev;
	current_ptr = item;
}


template<typename T>
void Iterator<T>::advance(int pos)
{
	for (int i = 0; i < pos; i++)
		this->next();
}

template<typename T>
void Iterator<T>::distance(int pos)
{
	for (int i = 0; i < pos; i++)
		this->prev();
}



template<typename T>
T& Iterator<T>::operator*() const
{
	auto item = current_ptr.lock();

	T& val = item->item;

	return val;
}


template<typename T>
Iterator<T>& Iterator<T>::operator++ ()
{
	this->next();

	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++ (int)
{
	Iterator<T> prev = *this;

	this->next();

	return prev;
}


template<typename T>
Iterator<T>& Iterator<T>::operator-- ()
{
	this->prev();

	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator-- (int)
{
	Iterator<T> prev = *this;

	this->prev();

	return prev;
}


template<typename T>
Iterator<T>& Iterator<T>::operator+= (int pos)
{
	this->advance(pos);

	return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator-= (int pos)
{
	this->distance(pos);

	return *this;
}


template<typename T>
bool Iterator<T>::operator== (const Iterator<T> & iter) const
{
	return this->current_ptr.lock() == iter.current_ptr.lock();
}

template<typename T>
bool Iterator<T>::operator!= (const Iterator<T> & iter) const
{
    return this->current_ptr.lock() != iter.current_ptr.lock();
}

