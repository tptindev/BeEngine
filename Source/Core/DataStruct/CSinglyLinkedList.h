#ifndef CSINGLYLINKEDLIST_H
#define CSINGLYLINKEDLIST_H

#include "CMemoryManager.h"
#include "ILinkedList.h"
#include "SNode.h"
template<typename T>
class CSinglyLinkedList: public ILinkedList
{
private:
    int m_count;
    SNode<T>*  m_head;
    SNode<T>*  m_tail;
public:
    CSinglyLinkedList()
    {
        m_count = 0;
        m_head = nullptr;
        m_tail = nullptr;
    }

    virtual void push_back(T data) override
    {
        SNode<T>* el = HEAP_ALLOC(SNode<T>,sizeof(SNode<T>));
        el->data = data;

        if(empty())
        {
            m_head = el;
            m_head->next = m_tail;
        }
        else
        {
            m_tail = el;
        }

        m_count++;
    }

    virtual bool empty() override
    {
        return m_count > 0;
    }
};

#endif // CSINGLYLINKEDLIST_H
