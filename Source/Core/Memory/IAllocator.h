#ifndef IALLOCATOR_H
#define IALLOCATOR_H

#include <stdint.h>

class IAllocator
{
public:
    virtual void *allocate(size_t) = 0;
    virtual void deallocate(void*) = 0;
};

#endif // IALLOCATOR_H
