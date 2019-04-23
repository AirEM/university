#pragma once

#include "listexception.h"

class ListBase
{
protected:
	int size_array;
	int position;
    const int initial_size = 10;
    const int magnification = 2;

public:
    virtual bool empty() const = 0;
    virtual int size() const = 0;
};
