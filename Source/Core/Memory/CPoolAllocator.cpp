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
        void* blockBegin = static_cast<void*>(malloc(blockSize));
        m_blocks.push_back(blockBegin);
        for (int chunk_index = 1; chunk_index < static_cast<int>(m_chunks_per_block); chunk_index++)
        {
            m_blocks.push_back(static_cast<char*>(m_blocks.back()) + chunkSize);
        }

        m_data = blockBegin;
    }

    return m_data;
}

void CPoolAllocator::deallocate(void *ptr, size_t size)
{
    memset(ptr, 0x0, size);
}
