#ifndef CSTACKALLOCATOR_H
#define CSTACKALLOCATOR_H

#include "IAllocator.h"

class CStackAllocator: public IAllocator
{
private:
    void* m_data;    // Pointer to the allocated memory
    size_t m_capacity;  // Total capacity of the stack
    size_t m_top;       // Current top of the stack

public:
    CStackAllocator(size_t size);
    ~CStackAllocator();

    size_t capacity() const;
    size_t top() const;

    // IAllocator interface
public:
    virtual void* allocate(size_t size) override;
    virtual void deallocate(void*) override;
};

#endif // CSTACKALLOCATOR_H
