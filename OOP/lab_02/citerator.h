#pragma once

#include "iterator.h"

template <typename T>
class cIterator : public Iterator<T>
{
private:
	using Iterator<T>::current_ptr;

public:
	cIterator(std::shared_ptr<ListItem<T>>&);

	~cIterator();

    const T& operator* ();
};



// sourse




template<typename T>
cIterator<T>::cIterator(std::shared_ptr<ListItem<T>>& ptr) : Iterator<T>(ptr)
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
