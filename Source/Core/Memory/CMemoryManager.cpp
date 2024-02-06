#include "CMemoryManager.h"
#include <Utils.h>
#include "CStackAllocator.h"

CMemoryManager *CMemoryManager::s_instance = nullptr;
CMemoryManager::CMemoryManager()
{
    m_allocators[ALLOC_KINDS::STACK] = new CStackAllocator(1024);
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
