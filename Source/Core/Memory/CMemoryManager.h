#ifndef CMEMORYMANAGER_H
#define CMEMORYMANAGER_H

#include "CStackAllocator.h"

class CMemoryManager
{

private:
    static CMemoryManager* s_instance;
    CMemoryManager();
    CStackAllocator *m_stack_alloc;
public:
    enum MEM_ALLOC_SEG: bool
    {
        STACK = 0,
        HEAP  = 1
    };

    CMemoryManager(CMemoryManager &other) = delete;
    void operator=(const CMemoryManager &) = delete;
    ~CMemoryManager();
    static CMemoryManager* instance();

    template<typename T>
    T* alloc(MEM_ALLOC_SEG seg, size_t size)
    {
        switch (seg) {
        case MEM_ALLOC_SEG::STACK:
            return static_cast<T*>(m_stack_alloc->allocate(size));
        default:
            return nullptr;
        }
    }
};

#define STACK_ALLOC(T,SIZE) CMemoryManager::instance()->alloc<T>(CMemoryManager::MEM_ALLOC_SEG::STACK,SIZE)

#endif // CMEMORYMANAGER_H
