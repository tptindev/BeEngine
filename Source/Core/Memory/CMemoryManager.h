#ifndef CMEMORYMANAGER_H
#define CMEMORYMANAGER_H

#include <map>
#include "AAllocator.h"

class CMemoryManager
{

private:
    static CMemoryManager* s_instance;
    CMemoryManager();
    ~CMemoryManager();

    std::map<unsigned char, AAllocator*> m_allocators;
public:
    enum ALLOC_KINDS: unsigned char
    {
        STACK = 0,
        POOL
    };

    CMemoryManager(CMemoryManager &other) = delete;
    void operator=(const CMemoryManager &) = delete;
    static CMemoryManager* instance();

    template<typename T, typename ...Args>
    T* alloc(ALLOC_KINDS kind, Args&&...args)
    {
        T* ptr = static_cast<T*>(m_allocators[kind]->allocate(sizeof(T)));
        *ptr = T(std::forward<Args>(args)...);
        return ptr;
    }

    template<typename T>
    void release(ALLOC_KINDS kind, T* ptr)
    {
        m_allocators[kind]->deallocate(ptr, sizeof(T));
    }
};

#define StackAlloc(T,...) CMemoryManager::instance()->alloc<T>(CMemoryManager::ALLOC_KINDS::STACK,##__VA_ARGS__)

#endif // CMEMORYMANAGER_H
