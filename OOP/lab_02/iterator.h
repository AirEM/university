#pragma once

#include "iteratorbase.h"

template <typename T>
class Iterator : public IteratorBase<T>
{
private:
    using IteratorBase<T>::current;

public:
    Iterator(T*);

	Iterator<T>& operator= (const Iterator<T>&);

	T& operator* () const;

	Iterator<T>& operator++ ();
	Iterator<T> operator++ (int);
	Iterator<T>& operator-- ();
	Iterator<T> operator-- (int);

	Iterator<T>& operator+= (int);
	Iterator<T>& operator-= (int);
	bool operator== (const Iterator<T>&);
	bool operator!= (const Iterator<T>&);
};



// sourse



template<typename T>
Iterator<T>::Iterator(T* arr)
{
	current = arr;
}


template<typename T>
Iterator<T>& Iterator<T>::operator= (const Iterator<T>& iter)
{
	current = iter.current;

	return *this;
}


template<typename T>
T& Iterator<T>::operator*() const
{
	return *current;
}


template<typename T>
Iterator<T>& Iterator<T>::operator++ ()
{
	current++;

	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++ (int)
{
	Iterator<T> prev = *this;

	++(*this);

	return prev;
}

template<typename T>
Iterator<T>& Iterator<T>::operator-- ()
{
	current--;

	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator-- (int)
{
	Iterator<T> prev = *this;

	--(*this);

	return prev;
}


template<typename T>
Iterator<T>& Iterator<T>::operator+= (int n)
{
	current += n;

	return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator-= (int n)
{
	current -= n;

	return *this;
}


template<typename T>
bool Iterator<T>::operator== (const Iterator<T> & iter)
{
	return current == iter.current;
}

template<typename T>
bool Iterator<T>::operator!= (const Iterator<T> & iter)
{
    return current != iter.current;;
}
