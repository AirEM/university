#pragma once

#include <iostream>

#include "listbase.h"
#include "iterator.h"
#include "citerator.h"

#include "listitem.h"


template <typename T>
class List : public ListBase
{
public:
    std::shared_ptr<ListItem<T>> begin_ptr;
    std::shared_ptr<ListItem<T>> current_ptr;
	std::shared_ptr<ListItem<T>> end_ptr;

public:
	explicit List(int);
	List(const List&);
	List(std::initializer_list<T>);
	~List();

    bool empty() const;
    int size() const;

    Iterator<T> begin() const;
    cIterator<T> cbegin() const;
	Iterator<T> end() const;
    cIterator<T> cend() const;

	T& front()const;
	T& back() const;

	void push_back(const T&);

	void push_front(const T&);

	void insert(int, const T&);

	void remove(int);

	void merge(const List<T>&);

	bool equals(const List<T>&);

	List<T>& operator= (const List<T>&);

	bool operator==(const List&);
	bool operator!=(const List&);
};



// sourse




template <typename T>
List<T>::List(int size)
{
    position = 0;

    ListItem<T> *item = new ListItem<T>;

    if (item == nullptr)
        throw MemoryListException();

    begin_ptr = std::make_shared<ListItem<T>>(*item);
	current_ptr = begin_ptr;

	std::shared_ptr<ListItem<T>> iter_ptr(begin_ptr);

    for (int i = 1; i < size; i++)
    {
        ListItem<T> *new_item = new ListItem<T>;

        if (new_item == nullptr)
                throw MemoryListException();

		std::shared_ptr<ListItem<T>> last_current_ptr = iter_ptr;

		iter_ptr = std::make_shared<ListItem<T>>(*new_item);
			
		iter_ptr->next.reset();
		iter_ptr->prev = last_current_ptr;

		last_current_ptr->next = iter_ptr;
    }

	end_ptr = iter_ptr;

	size_array = size;
}

template <typename T>
List<T>::List(const List& list) : List(list.position)
{
	std::shared_ptr<ListItem<T>> list_iter(list.begin_ptr);

	for (int i = 0; i < list.size(); i++)
	{
		this->push_back(list_iter->item);

		list_iter = list_iter->next;
	}
}

template <typename T>
List<T>::List(std::initializer_list<T> list) : List(list.size())
{
	for (T element : list)
		this->push_back(element);
}

template <typename T>
List<T>::~List()
{
	for (int i = 0; i < size_array; i++)
	{
		current_ptr = begin_ptr->next;
		
		begin_ptr->next.reset();
		begin_ptr->prev.reset();

		begin_ptr = current_ptr;
	}

	begin_ptr.reset();
	current_ptr.reset();
	end_ptr.reset();
}


template <typename T>
bool List<T>::empty() const
{
    return position == 0;
}

template <typename T>
int List<T>::size() const
{
    return position;
}


/*
template <typename T>
Iterator<T> List<T>::begin() const
{
    Iterator<T> iter(array);

	return iter;
}

template <typename T>
cIterator<T> List<T>::cbegin() const
{
    cIterator<T> iter(array);

    return iter;
}


template <typename T>
Iterator<T> List<T>::end() const
{
    Iterator<T> iter(array);
	iter += position;

	return iter;
}

template <typename T>
cIterator<T> List<T>::cend() const
{
    cIterator<T> iter(array);
    iter += position;

    return iter;
}
*/


template <typename T>
T& List<T>::front() const
{
	T& value = *(begin_ptr->item);

	return value;
}

template <typename T>
T& List<T>::back() const
{
	T& value = *(end_ptr->item);

	return value;
}


template <typename T>
void List<T>::push_back(const T& value)
{

	position++;
	current_ptr->item = value;


	if (position >= size_array)
	{
		ListItem<T>* item = new ListItem<T>;

		if (item == nullptr)
			throw MemoryListException();

		std::shared_ptr<ListItem<T>> new_ptr = std::make_shared<ListItem<T>>(*item);

		current_ptr->next = new_ptr;
		new_ptr->prev = current_ptr;
	}

	current_ptr = current_ptr->next;

}

template <typename T>
void List<T>::push_front(const T& value)
{
	ListItem<T>* item = new ListItem<T>;

	if (item == nullptr)
		throw MemoryListException();

	std::shared_ptr<ListItem<T>> new_ptr = std::make_shared<ListItem<T>>(*item);

	new_ptr->item = value;
	new_ptr->next = begin_ptr;

	begin_ptr.reset();
	begin_ptr = new_ptr;
	position++;
	size_array++;
}


template <typename T>
void List<T>::insert(int pos, const T & value)
{

    if (pos < 0 || position < pos)
    {
        throw IndexListException();
    }

	std::shared_ptr<ListItem<T>> iter_ptr(begin_ptr);
	

	for (int i = 0; i < pos - 1; i++)
		iter_ptr = iter_ptr->next;

	std::shared_ptr<ListItem<T>> next_iter_ptr(iter_ptr->next);

	ListItem<T>* item = new ListItem<T>;

	if (item == nullptr)
		throw MemoryListException();

	std::shared_ptr<ListItem<T>> new_ptr = std::make_shared<ListItem<T>>(*item);

	new_ptr->item = value;

	new_ptr->next = next_iter_ptr;
	new_ptr->prev = iter_ptr;

	iter_ptr->next = new_ptr;
	next_iter_ptr->prev = new_ptr;

	position++;
	size_array++;

}

/*
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

*/

template <typename T>
List<T>& List<T>::operator= (const List<T> & list)
{
	return List<T>(list);
}

/*
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
*/
