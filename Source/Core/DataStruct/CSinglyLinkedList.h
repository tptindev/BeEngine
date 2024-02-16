#ifndef CSINGLYLINKEDLIST_H
#define CSINGLYLINKEDLIST_H

#include "ILinkedList.h"

template<typename T>
class CSinglyLinkedList: public ILinkedList<T>
{
public:
    CSinglyLinkedList()
    {
        this->m_count = 0;
        this->m_head = nullptr;
        this->m_tail = nullptr;
    }

    typedef CIterator<T>  iterator;
    typedef const CIterator<T> const_iterator;

    template<class ...TArgs>
    void emplace_front(TArgs&& ...args)
    {
        SNode<T>* el = new SNode<T>(std::forward<TArgs>(args)...);
        if(this->empty())
        {
            this->m_head = el;
        }
        else
        {
            el->next = this->m_head;
            this->m_head = el;
        }
        this->m_count++;
    }

    template<class ...TArgs>
    void emplace_back(TArgs&& ...args)
    {
        SNode<T>* el = new SNode<T>(std::forward<TArgs>(args)...);
        if(this->empty())
        {
            this->m_head = el;
        }
        else
        {
            if(this->m_tail == nullptr)
            {
                this->m_tail = el;
                this->m_head->next = this->m_tail;
            }
            else
            {
                this->m_tail->next = el;
                this->m_tail = el;
            }
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
        if(this->m_head == nullptr)
        {
            std::cerr << "List is empty. Cannot pop_front.\n";
            return;
        }

        SNode<T>* front = this->m_head;
        this->m_head = this->m_head->next;
        safeRelease(front);
        this->m_count--;
    }

    void pop_back()
    {
        if(this->m_head == nullptr)
        {
            std::cerr << "List is empty. Cannot pop_back.\n";
            return;
        }

        if(this->m_head->next == nullptr)
        {
            this->m_count = 0;
            safeRelease(this->m_head);
            return;
        }

        SNode<T>* current = this->m_head;
        while(current != nullptr)
        {
            if(current->next == this->m_tail)
            {
                safeRelease(current->next);
                this->m_tail = current;
                this->m_tail->next = nullptr;
                break;
            }
            current = current->next;
        }

        this->m_count--;
    }

    template<class ...TArgs>
    void emplace(const_iterator position, TArgs&&...args)
    {
        SNode<T>* el = new SNode<T>(std::forward<TArgs>(args)...);
        iterator it = this->begin();
        while (it != this->end())
        {
            if(it == position)
            {
                break;
            }
            ++it;
        }
    }

    void clear()
    {
        SNode<T>* current = this->m_head;
        while(current != nullptr)
        {
            current = current->next;
        }
    }
};

#endif // CSINGLYLINKEDLIST_H
