#pragma once

template <typename T>
class IteratorBase
{
public:

	virtual ~IteratorBase() {};

	virtual void next() = 0;
	virtual void prev() = 0;

	virtual void advance(int) = 0;
	virtual void distance(int) = 0;
};




