#include "CMemoryManager.h"
#include <Utils.h>

CMemoryManager *CMemoryManager::s_instance = nullptr;
CMemoryManager::CMemoryManager()
{
    m_stack_alloc = new CStackAllocator(1024);
    m_heap_alloc  = new CHeapAllocator();
}

CMemoryManager::~CMemoryManager()
{
    safeRelease(m_stack_alloc);
    safeRelease(m_heap_alloc);
}

CMemoryManager *CMemoryManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CMemoryManager: s_instance;
}
