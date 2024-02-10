#ifndef COBJECT_H
#define COBJECT_H

#include "IObserver.h"
#include "CDoublyLinkedList.h"
#include "CSignalPool.h"
#include "CPoolAllocator.h"

class CObject: public IObserver
{
private:
    CDoublyLinkedList<CObject*> m_childs;
    CSignalPool* m_signal_pool;

public:
    static CPoolAllocator s_allocator;
    static void *operator new(size_t size);
    static void operator delete(void *ptr, size_t size);

public:
    explicit CObject(CObject* parent = nullptr);
    bool connect(CObject* sender, uint8_t signal, CObject* receiver);
};

#endif // COBJECT_H
