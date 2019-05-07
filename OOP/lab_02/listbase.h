#pragma once

#include "listexception.h"

class ListBase
{
public:
	int size_array;
	int position;

public:
    virtual bool empty() const = 0;
    virtual int size() const = 0;
	virtual ~ListBase() {};
};
