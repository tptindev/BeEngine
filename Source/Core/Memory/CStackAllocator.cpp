#include "CStackAllocator.h"
#include <cstdlib>
#include <LoggerDefines.h>

CStackAllocator::CStackAllocator(size_t size)
    :m_capacity(size), m_top(0)
{
    if(!m_data)
    {
        _DEBUG("Failed to allocate memory for StackAllocator!");
        std::exit(EXIT_FAILURE);
    }
}

CStackAllocator::~CStackAllocator()
{
    std::free(m_data);
}

void *CStackAllocator::allocate(size_t size)
{
    if((m_top + size) > m_capacity)
    {
        // Handle out-of-memory error
        _DEBUG("Out of memory in StackAllocator!");
        std::exit(EXIT_FAILURE);
    }

    void *ptr = static_cast<void*>((char*)m_data + m_top);

    m_top += size;

    return ptr;
}

size_t CStackAllocator::capacity() const
{
    return m_capacity;
}

size_t CStackAllocator::top() const
{
    return m_top;
}

