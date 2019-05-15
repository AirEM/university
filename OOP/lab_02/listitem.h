#pragma once

#include <memory>

template <typename T>
class ListItem
{
public:
	T item;
	std::shared_ptr<ListItem<T>> next;
	std::shared_ptr<ListItem<T>> prev;
};

