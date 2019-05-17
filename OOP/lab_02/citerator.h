#pragma once

#include "iterator.h"

template <typename T>
class cIterator : public Iterator<T>
{
private:
	using Iterator<T>::current_ptr;

public:
	cIterator(const std::shared_ptr<ListItem<T>>&);

	~cIterator();

    const T& operator* ();

	cIterator<T>& operator++ ();
	cIterator<T> operator++ (int);
	cIterator<T>& operator-- ();
	cIterator<T> operator-- (int);

	cIterator<T>& operator+= (int);
	cIterator<T>& operator-= (int);
};



// sourse




template<typename T>
cIterator<T>::cIterator(const std::shared_ptr<ListItem<T>>& ptr) : Iterator<T>(ptr)
{
}


template<typename T>
cIterator<T>::~cIterator()
{
	current_ptr.reset();
}


template <typename T>
const T& cIterator<T>::operator* ()
{
	auto item = current_ptr.lock();

	T& val = item->item;

	return val;
}


template<typename T>
cIterator<T>& cIterator<T>::operator++ ()
{
	this->next();

	return *this;
}

template<typename T>
cIterator<T> cIterator<T>::operator++ (int)
{
	Iterator<T> prev = *this;

	this->next();

	return prev;
}


template<typename T>
cIterator<T>& cIterator<T>::operator-- ()
{
	this->prev();

	return *this;
}

template<typename T>
cIterator<T> cIterator<T>::operator-- (int)
{
	Iterator<T> prev = *this;

	this->prev();

	return prev;
}


template<typename T>
cIterator<T>& cIterator<T>::operator+= (int pos)
{
	this->advance(pos);

	return *this;
}

template<typename T>
cIterator<T>& cIterator<T>::operator-= (int pos)
{
	this->distance(pos);

	return *this;
}
