#ifndef CITERATOR_H
#define CITERATOR_H

#include "SNode.h"

template<typename T>
class CIterator
{
private:
    SNode<T>* m_data;
public:
    CIterator(): m_data(nullptr){}
    CIterator(SNode<T>* head): m_data(head){}

    SNode<T> *operator->()
    {
        return m_data;
    }

    // Overload * operator to access the value
    T& operator*()
    {
        return m_data->data;
    }

    // Overload ++ operator to move to the next element
    CIterator& operator++()
    {
        if(m_data != nullptr)
        {
            m_data = m_data->next;
        }
        return *this;
    }

    // Overload != operator to check for inequality
    bool operator!=(const CIterator& other) const
    {
        return m_data != other.m_data;
    }

    // Overload == operator to check for inequality
    bool operator==(const CIterator& other) const
    {
        return m_data == other.m_data;
    }
    SNode<T> *data() const
    {
        return m_data;
    }
};

#endif // CITERATOR_H
