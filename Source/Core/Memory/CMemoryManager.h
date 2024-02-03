#ifndef CMEMORYMANAGER_H
#define CMEMORYMANAGER_H

#include "CStackAllocator.h"

class CMemoryManager
{
private:
    static CMemoryManager* s_instance;
    CMemoryManager();
    CStackAllocator m_stack_alloc;
public:
    CMemoryManager(CMemoryManager &other) = delete;
    void operator=(const CMemoryManager &) = delete;
    ~CMemoryManager();
    static CMemoryManager* instance();
};

#endif // CMEMORYMANAGER_H
