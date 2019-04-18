#pragma once

#include <iostream>

#include "listbase.h"
#include "iterator.h"
#include "listexception.h"



template <typename T>
class List : public ListBase<T>
{
private:
	T* array;

	using ListBase<T>::position;
	using ListBase<T>::size_array;
	using ListBase<T>::buf_size;

public:
	List();
	explicit List(int);
	List(const List&);
	List(std::initializer_list<T>);
	~List();

	Iterator<T> begin() const;
	Iterator<T> end() const;

	T& front()const;
	T& back() const;

	void push_back(const T&);
	void push_front(const T&);

	void insert(int, const T&);

	void remove(int);

	void merge(const List<T>&);

	bool equals(const List<T>&);

	T& operator[] (int) const;

	List<T>& operator= (const List<T>&);

	bool operator==(const List&);
	bool operator!=(const List&);

	using ListBase<T>::empty;
	using ListBase<T>::size;
};



// sourse



template <typename T>
List<T>::List()
{
	array = static_cast<T*>(malloc(size_array * sizeof(T)));

	if (array == nullptr)
		throw MemoryListException();
}

template <typename T>
List<T>::List(int size) : ListBase<T>::ListBase(size)
{
    array = static_cast<T*>(malloc(size_array * sizeof(T)));

    if (array == nullptr)
        throw MemoryListException();
}

template <typename T>
List<T>::List(const List & list) : List(list.position)
{
	position = list.position;
	memcpy(array, list.array, list.position * sizeof(T));
}

template <typename T>
List<T>::List(std::initializer_list<T> list) : List(list.size())
{
	for (T element : list)
		array[position++] = element;
}

template <typename T>
List<T>::~List()
{
	if (array != nullptr)
		free(array);
}


template <typename T>
Iterator<T> List<T>::begin() const
{
	Iterator<T> iter(array, position);

	return iter;
}

template <typename T>
Iterator<T> List<T>::end() const
{
	Iterator<T> iter(array, position);
	iter += position;

	return iter;
}


template <typename T>
T& List<T>::front() const
{
	T& value = nullptr;

	if (position > 0)
		value = array[0];

	return value;
}

template <typename T>
T& List<T>::back()const
{
	T& value = nullptr;

	if (position > 0)
		value = array[position - 1];

	return value;
}


template <typename T>
void List<T>::push_back(const T & value)
{
	T* copy_array;

	if (position == size_array)
	{
		copy_array = array;

		size_array += buf_size;
		array = static_cast<T*>(realloc(array, size_array * sizeof(T)));

		if (array == nullptr)
		{
			array = copy_array;
			throw MemoryListException();
		}
	}

	array[position++] = value;
}

template <typename T>
void List<T>::push_front(const T & value)
{
	T* copy_array;

	if (position == size_array)
	{
		copy_array = array;

		size_array += buf_size;
		array = static_cast<T*>(realloc(array, size_array * sizeof(T)));

		if (array == nullptr)
		{
			array = copy_array;
			throw MemoryListException();
		}
	}

	for (int i = position; i > 0; i--)
		array[i] = array[i - 1];

	array[0] = value;
	position++;
}


template <typename T>
void List<T>::insert(int pos, const T & value)
{
	T* copy_array;

    if (pos < 0 || position < pos)
    {
        throw IndexListException();
    }

	if (position == size_array)
	{
		copy_array = array;

		size_array += buf_size;
		array = static_cast<T*>(realloc(array, size_array * sizeof(T)));

		if (array == nullptr)
		{
			array = copy_array;
			throw MemoryListException();
		}
	}

	for (int i = position; i > pos; i--)
		array[i] = array[i - 1];

	array[pos] = value;

	position++;
}

template <typename T>
void List<T>::remove(int pos)
{
	if (pos < 0 || position < pos)
		throw IndexListException();

	for (int i = pos; i < position; i++)
		array[i] = array[i + 1];

	position--;
}


template <typename T>
void List<T>::merge(const List<T> & list)
{
	for (int i = 0; i < list.size(); i++)
		this->push_back(list[i]);
}

template <typename T>
bool List<T>::equals(const List<T> & list)
{
	bool status = true;

	T* current_array = this->array;
	T* other_array = list.array;

	if (this->position == list.position)
	{
		for (int i = 0; i < this->position; i++)
			if (current_array[i] != other_array[i])
			{
				status = false;
				break;
			}
	}
	else
		status = false;

	return status;
}


template <typename T>
T& List<T>::operator[](int pos) const
{
	if (pos < 0 || position < pos)
		throw IndexListException();

	return array[pos];
}


template <typename T>
List<T>& List<T>::operator= (const List<T> & list)
{
	return List<T>(list);
}


template <typename T>
bool List<T>::operator==(const List & list)
{
	return this->equals(list);
}

template <typename T>
bool List<T>::operator!=(const List & list)
{
	return !(this->equals(list));
}
