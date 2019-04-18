#pragma once

#include "iteratorbase.h"
#include "iteratorexception.h"

template <typename T>
class Iterator : public IteratorBase<T>
{
private:
	T* begin;
	T* end;

    using IteratorBase<T>::current;

public:
	Iterator(T*, int);

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
Iterator<T>::Iterator(T* arr, int size)
{
	begin = arr;
	current = arr;
	end = arr + size;
}


template<typename T>
Iterator<T>& Iterator<T>::operator= (const Iterator<T>& iter)
{
	begin = iter.begin;
	current = iter.current;
	end = iter.end;

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
    if (current == end)
        throw IndexIteratorException();

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
    if (current == begin)
    {
        throw IndexIteratorException();
    }

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
    if (current + n > end)
    {
        throw IndexIteratorException();
    }

	current += n;

	return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator-= (int n)
{
    if (current - n < begin)
    {
        throw IndexIteratorException();
    }

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
	return current != iter.current;
}
