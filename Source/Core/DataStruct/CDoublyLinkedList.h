#ifndef C_DOUBLYLINKEDLIST_H
#define C_DOUBLYLINKEDLIST_H

#include <Utils.h>
#include "ALinkedList.h"
#include "CIterator.h"
#include "SNode.h"

template<typename T>
class CDoublyLinkedList: public ALinkedList<T>
{
public:
    CDoublyLinkedList()
    {
        this->m_count = 0;
        this->m_head = nullptr;
        this->m_tail = nullptr;
    }

    CDoublyLinkedList(const T& value)
    {
        this->m_count = 0;
        this->m_head = nullptr;
        this->m_tail = nullptr;
        push_back(value);
    }


    typedef CIterator<T>  iterator;
    typedef const CIterator<T> const_iterator;

    T& operator[](unsigned int index)
    {
        if (index < 0 || index >= this->m_count) {
            throw std::out_of_range("Index out of range");
        }
        SNode<T>* current = this->head();
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    template<class ...TArgs>
    void emplace_front(TArgs&& ...args)
    {
        SNode<T>* el = new SNode<T>(std::forward<TArgs>(args)...);
        if(this->m_head == nullptr)
        {
            this->m_head = this->m_tail = el;
        }
        else
        {
            el->next = this->m_head;
            this->m_head->pre = el;
            this->m_head = el;
        }
        this->m_count++;
    }

    template<class ...TArgs>
    void emplace_back(TArgs&& ...args)
    {
        SNode<T>* el = new SNode<T>(std::forward<TArgs>(args)...);
        if(this->m_head == nullptr)
        {
            this->m_head = this->m_tail = el;
        }
        else
        {
            this->m_tail->next = el;
            el->pre = this->m_tail;
            this->m_tail = el;
        }

        this->m_count++;
    }

    void push_front(T data)
    {
        emplace_front(data);
    }

    void push_back(T data)
    {
        emplace_back(data);
    }

    void pop_front()
    {
        if (this->m_head == nullptr)
        {
            std::cerr << "List is empty. Cannot pop_front.\n";
            return;
        }

        if (this->m_head == this->m_tail)
        {
            delete this->m_head;
            this->m_head = this->m_tail = nullptr;
        }
        else
        {
            this->m_head = this->m_head->next;
            delete this->m_head->pre;;
            this->m_head->pre = nullptr;
        }

        this->m_count--;
    }

    void pop_back()
    {
        if (this->m_head == nullptr)
        {
            std::cerr << "List is empty. Cannot pop_back.\n";
            return;
        }

        if (this->m_head == this->m_tail)
        {
            delete this->m_tail;
            this->m_tail = nullptr;
        }
        else
        {
            this->m_tail = this->m_tail->pre;
            delete this->m_tail->next;
            this->m_tail->next = nullptr;
        }

        this->m_count--;
    }

    iterator erase(iterator position)
    {
        iterator it = this->begin();
        if(position == it)
        {
            pop_front();
            return this->begin();
        }

        else if(position == iterator(this->m_tail))
        {
            pop_back();
            return this->end();
        }


        while (it != this->end())
        {
            if(it == position)
            {
                it->pre->next = it->next;
                it->next->pre = it->pre;
                this->m_count--;
                break;
            }
            ++it;
        }
        return ++it;
    }

    iterator erase(iterator first, iterator last)
    {
        iterator &it = first;
        while (it != last)
        {
            erase(it);
            this->m_count--;
        }
        return ++it;
    }
};

#endif // C_DOUBLYLINKEDLIST_H
