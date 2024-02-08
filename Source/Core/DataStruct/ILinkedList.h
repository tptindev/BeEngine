#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

#include <iostream>
#include <stdint.h>
#include <Utils.h>
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
    friend std::ostream &operator<<(std::ostream &out, ILinkedList *list)
    {
        out << "[" << &list << "] Linked List: " << std::endl;
        if(list->empty())
        {
            out << "EMPTY" << std::endl;
        }
        else
        {
            int i = 0;;
            SNode<T> *ptr = list->m_head;
            while (ptr != nullptr) {
                out << "[" << ptr << "][" << i << "][" << ptr->data << "]" << std::endl;
                ptr = ptr->next;
                i++;
            }
        }

        out << "Total: " << list->count() << std::endl;

        return out;
    }

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

    bool empty()
    {
        return (this->m_count < 1 && this->m_head == nullptr);
    }

    uint32_t count() const
    {
        return m_count;
    }

    SNode<T> *head() const
    {
        return m_head;
    }

    SNode<T> *tail() const
    {
        return m_tail;
    }
};




#endif // ILINKEDLIST_H
