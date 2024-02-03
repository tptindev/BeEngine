#ifndef CPOOLALLOCATOR_H
#define CPOOLALLOCATOR_H

#include "IAllocator.h"

class CPoolAllocator: public IAllocator
{
public:
    CPoolAllocator();

    // IAllocator interface
public:
    virtual void *allocate(size_t) override;
    virtual void deallocate(void *) override;
};

#endif // CPOOLALLOCATOR_H
