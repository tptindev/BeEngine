#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

#include <stdint.h>
#include "SNode.h"
#include "CIterator.h"

template<typename T>
class ILinkedList
{
protected:
    uint32_t  m_count;
    SNode<T>* m_head;
    SNode<T>* m_tail;

public:
    CIterator<T> begin()
    {
        return CIterator<T>(m_head);
    }

    CIterator<T> end()
    {
        return CIterator<T>(nullptr);
    }

    T &front()
    {
        return m_head->data;
    }

    T &back()
    {
        return m_tail->data;
    }
};

#endif // ILINKEDLIST_H
