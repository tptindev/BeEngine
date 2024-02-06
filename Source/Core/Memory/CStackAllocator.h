#ifndef CSTACKALLOCATOR_H
#define CSTACKALLOCATOR_H

#include "AAllocator.h"

class CStackAllocator: public AAllocator
{
private:
    char   m_data;    // Pointer to the allocated memory
    size_t m_top;       // Current top of the stack

public:
    CStackAllocator();
    CStackAllocator(size_t size);
    ~CStackAllocator();

    size_t top() const;

    // IAllocator interface
public:
    virtual void* allocate(size_t) override;
    virtual void deallocate(void*, size_t) override;
};

#endif // CSTACKALLOCATOR_H
