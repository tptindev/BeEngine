#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

#include <stdint.h>
#include "SNode.h"

template<typename T>
class ILinkedList
{
protected:
    uint32_t  m_count;
    SNode<T>* m_head;
    SNode<T>* m_tail;

};

#endif // ILINKEDLIST_H
