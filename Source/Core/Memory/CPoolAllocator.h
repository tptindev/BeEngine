#ifndef CPOOLALLOCATOR_H
#define CPOOLALLOCATOR_H

#include "AAllocator.h"

class CPoolAllocator: public AAllocator
{
public:
    CPoolAllocator();

    // IAllocator interface
public:
    virtual void *allocate(size_t) override;
    virtual void deallocate(void *, size_t) override;
};

#endif // CPOOLALLOCATOR_H
