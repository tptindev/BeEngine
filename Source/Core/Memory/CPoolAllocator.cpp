#include "CPoolAllocator.h"
#include <Utils.h>
#include <cstring>


CPoolAllocator::CPoolAllocator(size_t chunks_per_block)
    :m_chunks_per_block(chunks_per_block), m_data(nullptr)
{

}

void *CPoolAllocator::allocate(size_t chunkSize)
{
    if(m_data == nullptr)
    {

    }

    return m_data;
}

void CPoolAllocator::deallocate(void *ptr, size_t size)
{
    memset(ptr, 0x0, size);
}
