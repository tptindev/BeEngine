#ifndef CSTACKALLOCATOR_H
#define CSTACKALLOCATOR_H

#include <stdint.h>

class CStackAllocator
{
private:
    void* m_data;    // Pointer to the allocated memory
    size_t m_capacity;  // Total capacity of the stack
    size_t m_top;       // Current top of the stack

public:
    CStackAllocator(size_t size);
    ~CStackAllocator();

    void* allocate(size_t size);

    size_t capacity() const;
    size_t top() const;
};

#endif // CSTACKALLOCATOR_H
