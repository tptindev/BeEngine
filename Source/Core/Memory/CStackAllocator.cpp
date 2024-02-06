#include "CStackAllocator.h"
#include <cstdlib>
#include <cstring>
#include <LoggerDefines.h>

CStackAllocator::CStackAllocator()
    :m_top(0)
{
    _DEBUG("Entry");
    m_capacity = 0;
    if(!m_data)
    {
        _DEBUG("Failed to allocate memory for StackAllocator!");
        std::exit(EXIT_FAILURE);
    }
}

CStackAllocator::CStackAllocator(size_t size)
    :m_top(0)
{
    _DEBUG("Entry");
    m_capacity = size;
    if(!m_data)
    {
        _DEBUG("Failed to allocate memory for StackAllocator!");
        std::exit(EXIT_FAILURE);
    }
}

CStackAllocator::~CStackAllocator()
{
    _DEBUG("Entry");
    memset(&m_data, 0x0, capacity());
}

void *CStackAllocator::allocate(size_t size)
{
    if((m_top + size) > m_capacity)
    {
        // Handle out-of-memory error
        _DEBUG("Out of memory in StackAllocator!");
        std::exit(EXIT_FAILURE);
    }

    void *ptr = static_cast<void*>(&m_data + m_top);
    m_top += size;

    return ptr;
}

void CStackAllocator::deallocate(void *, size_t size)
{
    // do nothing
}

size_t CStackAllocator::top() const
{
    return m_top;
}

