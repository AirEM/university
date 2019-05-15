#pragma once

#include "listexception.h"

class ListBase
{
protected:
	int list_size;

public:
    virtual bool empty() const = 0;
    virtual int size() const = 0;
	virtual ~ListBase() {};
};
