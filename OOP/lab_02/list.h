#pragma once

#include <iostream>

#include "listbase.h"
#include "iterator.h"
#include "citerator.h"

#include "listitem.h"


template <typename T>
class List : public ListBase
{
public: // must be PRIVATE !!!
    std::shared_ptr<ListItem<T>> begin_ptr;
    std::shared_ptr<ListItem<T>> current_ptr;

	std::shared_ptr<ListItem<T>> get_item_ptr(const T&);

public:
	explicit List();
	List(const List&);
	List(std::initializer_list<T>);
	~List();

    bool empty() const override;
    int size() const override;

    Iterator<T> begin() const;
    cIterator<T> cbegin() const;
	Iterator<T> end() const;
    cIterator<T> cend() const;

	T& front() const;
	T& back() const;

	void push_back(const T&);

	void push_front(const T&);

	void insert(int, const T&);

	void remove(int);
	void clear();

	void merge(List<T>&);

	bool equals(const List<T>&);

	List<T>& operator= (const List<T>&);

	bool operator==(const List&);
	bool operator!=(const List&);
};



// sourse


template <typename T>
std::shared_ptr<ListItem<T>> List<T>::get_item_ptr(const T& value)
{
	ListItem<T>* item = new ListItem<T>;

	if (item == nullptr)
		throw MemoryListException();

	std::shared_ptr<ListItem<T>> new_ptr = std::make_shared<ListItem<T>>(*item);
	new_ptr->item = value;
	new_ptr->next = nullptr;
	new_ptr->prev = nullptr;

	return new_ptr;
}


// main_sourse


template <typename T>
List<T>::List()
{
    list_size = 0;

}

template <typename T>
List<T>::List(const List& list) : List()
{
	std::shared_ptr<ListItem<T>> list_iter(list.begin_ptr);

	for (int i = 0; i < list.size(); i++)
	{
		this->push_back(list_iter->item);

		list_iter = list_iter->next;
	}
}

template <typename T>
List<T>::List(std::initializer_list<T> list) : List()
{
	for (T element : list)
		this->push_back(element);
}

template <typename T>
List<T>::~List()
{
	clear();
}


template <typename T>
bool List<T>::empty() const
{
    return list_size == 0;
}

template <typename T>
int List<T>::size() const
{
    return list_size;
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
	T& value = *(current_ptr->item);

	return value;
}


template <typename T>
void List<T>::push_back(const T& value)
{
	std::shared_ptr<ListItem<T>> new_ptr = get_item_ptr(value);


	if (begin_ptr)
	{
		current_ptr->next = new_ptr;
		new_ptr->prev = current_ptr;

		current_ptr = current_ptr->next;
	}
	else
	{
		begin_ptr = new_ptr;
		current_ptr = new_ptr;
	}


	list_size++;
}

template <typename T>
void List<T>::push_front(const T& value)
{
	std::shared_ptr<ListItem<T>> new_ptr = get_item_ptr(value);

	if (begin_ptr)
	{
		new_ptr->next = begin_ptr;
		begin_ptr->prev = new_ptr;

		begin_ptr = begin_ptr->prev;
	}
	else
	{
		begin_ptr = new_ptr;
		current_ptr = new_ptr;
	}

	list_size++;
}


template <typename T>
void List<T>::insert(int pos, const T & value)
{
    if (pos < 0 || list_size <= pos)
        throw IndexListException();

	if (pos == 0)
		this->push_front(value);
	else
	{
		std::shared_ptr<ListItem<T>> new_ptr = get_item_ptr(value);

		std::shared_ptr<ListItem<T>> before_ptr(begin_ptr);
		for (int i = 0; i < pos - 1; i++)
			before_ptr = before_ptr->next;

		std::shared_ptr<ListItem<T>> after_ptr(before_ptr->next);

		if (after_ptr)
		{
			after_ptr->prev = new_ptr;
			new_ptr->next = after_ptr;
		}
		else
			current_ptr = new_ptr;

		new_ptr->prev = before_ptr;
		before_ptr->next = new_ptr;
	}
	
	list_size++;
}


template <typename T>
void List<T>::remove(int pos)
{
	if (pos < 0 || list_size <= pos)
		throw IndexListException();

	if (pos == 0)
	{
		begin_ptr = begin_ptr->next;
		begin_ptr->next.reset();
	}
	else
	{
		std::shared_ptr<ListItem<T>> befor_ptr(begin_ptr);

		for (int i = 0; i < pos - 1; i++)
			befor_ptr = befor_ptr->next;

		std::shared_ptr<ListItem<T>> after_ptr(befor_ptr->next->next);

		if (after_ptr)
			after_ptr->prev = befor_ptr;
		else
			current_ptr = current_ptr->prev;

		befor_ptr->next = after_ptr;
	}

	list_size--;
}

template <typename T>
void List<T>::clear()
{
	for (int i = 0; i < this->list_size; i++)
	{
		current_ptr = begin_ptr->next;

		begin_ptr->next.reset();
		begin_ptr->prev.reset();

		begin_ptr = current_ptr;
	}

	begin_ptr.reset();
	current_ptr.reset();

	list_size = 0;
}



template <typename T>
void List<T>::merge(List<T> & list)
{
	this->current_ptr->next = list.begin_ptr;
	this->current_ptr = list.current_ptr;

	this->list_size += list.list_size;

	list.list_size = 0;
	list.begin_ptr.reset();
	list.current_ptr.reset();
}


template <typename T>
bool List<T>::equals(const List<T> & list)
{
	bool status = true;

	std::shared_ptr<ListItem<T>> current_ptr(begin_ptr);
	std::shared_ptr<ListItem<T>> other_ptr(list.begin_ptr);

	if (this->list_size == list.list_size)
	{
		for (int i = 0; i < this->list_size; i++)
		{
			if (current_ptr->item != other_ptr->item)
			{
				status = false;
				break;
			}

			current_ptr = current_ptr->next;
			other_ptr = other_ptr->next;
		}
	}
	else
		status = false;

	return status;
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

