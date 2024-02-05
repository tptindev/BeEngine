#ifndef CITERATOR_H
#define CITERATOR_H

#include "SNode.h"

template<typename T>
class CIterator
{
private:
    SNode<T>* m_it_head;
public:
    CIterator(SNode<T>* head)
    {
        m_it_head = head;
    }

    // Overload * operator to access the value
    T& operator*()
    {
        return m_it_head->data;
    }

    // Overload ++ operator to move to the next element
    CIterator& operator++()
    {
        if(m_it_head != nullptr)
        {
            m_it_head = m_it_head->next;
        }
        return *this;
    }

    // Overload != operator to check for inequality
    bool operator!=(const CIterator& other) const
    {
        return m_it_head != other.m_it_head;
    }

    // Overload != operator to check for inequality
    bool operator==(const CIterator& other) const
    {
        return m_it_head == other.m_it_head;
    }
};


#endif // CITERATOR_H
