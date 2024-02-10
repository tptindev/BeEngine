#ifndef CPOOLALLOCATOR_H
#define CPOOLALLOCATOR_H

#include "AAllocator.h"
#include "CDoublyLinkedList.h"

class CPoolAllocator: public AAllocator
{
private:
    CDoublyLinkedList<void*>    m_pool;
    size_t m_chunks_per_block;
    void* m_data; // Pointer to the allocated memory

public:
    CPoolAllocator(size_t);

    // IAllocator interface
public:
    virtual void *allocate(size_t chunks = 1) override;
    virtual void deallocate(void *, size_t) override;
};

#endif // CPOOLALLOCATOR_H
