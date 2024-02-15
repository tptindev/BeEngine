#ifndef COBJECT_H
#define COBJECT_H

#include <functional>
#include "IObserver.h"
#include "CDoublyLinkedList.h"
#include "CSignalPool.h"
#include "CPoolAllocator.h"

class CObject: public IObserver
{
private:
    static CPoolAllocator s_allocator;
    CDoublyLinkedList<CObject*> m_childs;
    CSignalPool* m_signal_pool;

public:
    explicit CObject(CObject* parent = nullptr);

    template<typename PointerToMemberFunction, typename Functor>
    static bool connect(CObject* sender, PointerToMemberFunction signal, CObject* receiver, PointerToMemberFunction slot);

    //    static void *operator new[](size_t size);
    //    static void *operator new(size_t size);
    //    static void operator delete(void *ptr, size_t size);

};

#endif // COBJECT_H
