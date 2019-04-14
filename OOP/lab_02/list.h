#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <iostream>

template <typename T>
class List
{

private:
    T *array;
    int size_array;
    int index;
    const int buf_size = 10;

public:
    List();
    explicit List(int);
    List(const List&);
    List(std::initializer_list<T>);
    ~List();

    bool empty();
    int size();

    T& front();
    T& back();

    void push_back(const T&);
    void push_front(const T&);

    void insert(int, const T&);

    T operator[](int);
    bool operator==(const List&);


    // operator!=

    // итератор begin end

};

#include "list_sourse.h"

#endif // LIST_H
