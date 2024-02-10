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
        size_t blockSize = m_chunks_per_block * chunkSize;
        void* beginPtr = reinterpret_cast<void*>(malloc(blockSize));
        void* iterator  = beginPtr;
        for(int i = 0; i < static_cast<int>(m_chunks_per_block); i++)
        {
            m_pool.push_back(reinterpret_cast<void*>((char*)iterator + chunkSize));
        }
        return beginPtr;
    }
    return m_data;
}

void CPoolAllocator::deallocate(void *ptr, size_t size)
{
    memset(ptr, 0x0, size);
}
