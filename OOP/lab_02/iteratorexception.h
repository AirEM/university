#include <exception>

// Base class

class IteratorException : public std::exception
{};

// Index error

class IndexIteratorException : public IteratorException
{
public:
    virtual const char* what() const noexcept override
    {
        return "Iterator is out of List.";
    }
};
