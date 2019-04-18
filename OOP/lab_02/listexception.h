#pragma once

#include <exception>

// Base class

class ListException : public std::exception
{};

// Memory error

class MemoryListException : public ListException
{
public:
	virtual const char* what() const noexcept override
	{
		return "A memory allocation error.";
	}
};

// Index error

class IndexListException : public ListException
{
public:
	virtual const char* what() const noexcept override
	{
		return "List is out of range.";
	}
};
