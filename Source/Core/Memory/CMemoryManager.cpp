#include "CMemoryManager.h"
#include <Utils.h>
#include "CStackAllocator.h"
#include "CPoolAllocator.h"

CMemoryManager *CMemoryManager::s_instance = nullptr;
CMemoryManager::CMemoryManager()
{
    const size_t stack_capacity = 1024;
    const size_t chunks_per_block = 8;
    m_allocators[ALLOC_KINDS::STACK] = new CStackAllocator(stack_capacity);
    m_allocators[ALLOC_KINDS::POOL]  = new CPoolAllocator(chunks_per_block);
}

CMemoryManager::~CMemoryManager()
{
    for(auto it: m_allocators)
    {
        safeRelease(it.second);
    }
}

CMemoryManager *CMemoryManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CMemoryManager: s_instance;
}
