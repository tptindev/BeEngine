#include "CMemoryManager.h"

CMemoryManager *CMemoryManager::s_instance = nullptr;
CMemoryManager::CMemoryManager()
{
    m_stack_alloc = new CStackAllocator(1024);
}

CMemoryManager::~CMemoryManager()
{

}

CMemoryManager *CMemoryManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CMemoryManager: s_instance;
}
