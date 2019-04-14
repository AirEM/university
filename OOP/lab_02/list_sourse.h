#include "list.h"


template <typename T>
List<T>::List() : size_array(buf_size), index(0)
{
    array = static_cast<T*>(malloc(size_array * sizeof (T)));
}

template <typename T>
List<T>::List(int size) : size_array(size), index(0)
{
    array = static_cast<T*>(malloc(size_array * sizeof (T)));
}

template <typename T>
List<T>::List(const List& list) : List(list.index)
{
    index = list.index;
    memcpy(array, list.array, list.index * sizeof (T));
}

template <typename T>
List<T>::List(std::initializer_list<T> list) : List(list.size())
{
    for (T element : list)
        array[index++] = element;
}

template <typename T>
List<T>::~List()
{
    if (array != nullptr)
        free(array);
}


template <typename T>
bool List<T>::empty()
{
    return index == 0;
}

template <typename T>
int List<T>::size()
{
    return index;
}


template <typename T>
T& List<T>::front()
{
    T& value = nullptr;

    if (index > 0)
        value = array[0];

    return value;
}

template <typename T>
T& List<T>::back()
{
    T& value = nullptr;

    if (index > 0)
        value = array[index - 1];

    return value;
}


template <typename T>
void List<T>::push_back(const T& value)
{
    if (index != size_array)
        array[index++] = value;
    else
    {
        size_array += buf_size;
        array = static_cast<T*>(realloc(array, size_array * sizeof (T)));
        array[index++] = value;
    }
}

template <typename T>
void List<T>::push_front(const T& value)
{
    if (index != size_array)
    {
        for (int i = index; i > 0; i--)
            array[i] = array[i - 1];

        array[0] = value;
    }
    else
    {
        size_array += buf_size;
        array = static_cast<T*>(realloc(array, size_array * sizeof (T)));

        for (int i = index; i > 0; i--)
            array[i] = array[i - 1];

        array[0] = value;
    }
}


template <typename T>
void List<T>::insert(int pos, const T& value)
{
    if (index != size_array)
    {
        for (int i = index; i > pos; i--)
            array[i] = array[i - 1];

        array[pos] = value;
    }
    else
    {
        size_array += buf_size;
        array = static_cast<T*>(realloc(array, size_array * sizeof (T)));

        for (int i = index; i > pos; i--)
            array[i] = array[i - 1];

        array[pos] = value;
    }
}


template <typename T>
T List<T>::operator[](int n)
{
    if (0 <= n && n <=index)
        return array[n];
    else
        throw ;
}

template <typename T>
bool List<T>::operator==(const List& list)
{
    bool status = true;

    T* current_array = this->array;
    T* other_array = list.array;

    if (this->index == list.index)
    {
        for (int i = 0; i < this->index; i++)
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
