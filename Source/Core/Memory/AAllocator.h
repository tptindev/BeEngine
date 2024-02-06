#ifndef AALLOCATOR_H
#define AALLOCATOR_H

#include <stdint.h>

class AAllocator
{
protected:
    size_t m_capacity;  // Total capacity of the stack

public:
    inline size_t capacity() const { return m_capacity; }

    // Interface
    virtual void *allocate(size_t) = 0;
    virtual void deallocate(void*, size_t) = 0;
};

#endif // AALLOCATOR_H
