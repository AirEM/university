#pragma once

template <typename T>
class ListBase
{
protected:
	int size_array;
	int position;
	const int buf_size = 10;

public:
	ListBase();
	ListBase(int);

	bool empty() const;
	int size() const;

};


// sourse

template <typename T>
ListBase<T>::ListBase()
{
    size_array = buf_size;
    position = 0;
}

template <typename T>
ListBase<T>::ListBase(int size) : size_array(size)
{
    position = 0;
}


template <typename T>
bool ListBase<T>::empty() const
{
	return position == 0;
}

template <typename T>
int ListBase<T>::size() const
{
	return position;
}
