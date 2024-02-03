#ifndef CHEAPALLOCATOR_H
#define CHEAPALLOCATOR_H

#include "IAllocator.h"

class CHeapAllocator: public IAllocator
{
public:
    CHeapAllocator();
    ~CHeapAllocator();

    // IAllocator interface
public:
    virtual void *allocate(size_t) override;
    virtual void deallocate(void *) override;
};

#endif // CHEAPALLOCATOR_H
