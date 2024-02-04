#ifndef CDOUBLYLINKEDLIST_H
#define CDOUBLYLINKEDLIST_H

#include "ILinkedList.h"

template<typename T>
class CDoublyLinkedList: public ILinkedList<T>
{
public:
    CDoublyLinkedList()
    {
        this->m_count = 0;
        this->m_head = nullptr;
        this->m_tail = nullptr;
    }
};

#endif // CDOUBLYLINKEDLIST_H
