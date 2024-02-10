#include "CObject.h"
#define CHUNKS_PER_BLOCK 8

CPoolAllocator CObject::s_allocator(CHUNKS_PER_BLOCK);
CObject::CObject(CObject *parent)
{
    if(parent != nullptr)
    {
        parent->m_childs.push_back(this);
    }

    m_signal_pool =  CSignalPool::instance();
}

void *CObject::operator new[](size_t size)
{
    return s_allocator.allocate(size);
}

void *CObject::operator new(size_t size)
{
    return s_allocator.allocate(size);
}

void CObject::operator delete(void *ptr, size_t size)
{
    s_allocator.deallocate(ptr, size);
}
