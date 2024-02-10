#include "CPoolAllocator.h"
#include <Utils.h>
#include <cstring>


CPoolAllocator::CPoolAllocator(size_t chunks_per_block)
    :m_chunks_per_block(chunks_per_block)
{

}

void *CPoolAllocator::allocate(size_t chunks)
{
    if(m_data == nullptr)
    {
        size_t blockSize = m_chunks_per_block * chunks;


        void* ptr = reinterpret_cast<void*>(malloc(blockSize));
        m_pool.push_back(ptr);
    }
    return m_data;
}

void CPoolAllocator::deallocate(void *ptr, size_t size)
{
    memset(ptr, 0x0, size);
}
