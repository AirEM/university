#pragma once

#include "iterator.h"

template <typename T>
class cIterator : public Iterator<T>
{
private:
    using IteratorBase<T>::current;

public:
    cIterator(T* arr);

    const T& operator* () const;
};



// sourse




template<typename T>
cIterator<T>::cIterator(T* arr)
{
    current = arr;
}


template <typename T>
const T& cIterator<T>::operator* () const
{
    return *current;
}
