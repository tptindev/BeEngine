#include "CMemoryManager.h"

CMemoryManager *CMemoryManager::s_instance = nullptr;
CMemoryManager::CMemoryManager()
{

}

CMemoryManager::~CMemoryManager()
{

}

CMemoryManager *CMemoryManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CMemoryManager: s_instance;
}
