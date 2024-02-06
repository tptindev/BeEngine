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
            this->m_head->previous = el;
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
                this->m_tail->previous = this->m_head;
                this->m_head->next = this->m_tail;
            }
            else
            {
                el->previous = this->m_tail;
                this->m_tail->next = el;
                this->m_tail = el;
            }
        }

        this->m_count++;
    }

    void push_front(T data)
    {
        SNode<T> *el = new SNode<T>(data);
        if (this->empty())
        {
            this->m_head = el;
        }
        else
        {
            this->m_head->previous = el;
            el->next = this->m_head;
            this->m_head = el;
        }
        this->m_count++;
    }

    void push_back(T data)
    {
        SNode<T> *el = new SNode<T>(data);
        if (this->empty())
        {
            this->m_head = el;
        }
        else
        {
            if (this->m_tail == nullptr)
            {
                this->m_tail = el;
                this->m_tail->previous = this->m_head;
                this->m_head->next = this->m_tail;
            }
            else
            {
                el->previous = this->m_tail;
                this->m_tail->next = el;
                this->m_tail = el;
            }
        }

        this->m_count++;
    }

    void pop_front()
    {
        if (this->m_head == nullptr)
        {
            std::cerr << "List is empty. Cannot pop_front.\n";
            return;
        }

        SNode<T> *front = this->m_head;

        this->m_head = front->next;
        this->m_head->previous = nullptr;

        safeRelease(front);
        this->m_count--;
    }

    void pop_back()
    {
        if (this->m_head == nullptr)
        {
            std::cerr << "List is empty. Cannot pop_back.\n";
            return;
        }

        if (this->m_head->next == nullptr)
        {
            this->m_count = 0;
            safeRelease(this->m_head);
            return;
        }

        SNode<T> *tail = this->m_tail;
        this->m_tail = this->m_tail->previous;
        this->m_tail->next = nullptr;
        safeRelease(tail);
        this->m_count--;
    }

    CIterator<T> erase(CIterator<T> position)
    {
        CIterator<T> it = this->begin();
        while (it != this->end())
        {
            if(it == position)
            {
                return it;
            }
            ++it;
        }
        return this->end();
    }

    CIterator<T> erase(CIterator<T> first, CIterator<T> last)
    {
        while (first != last)
        {
            if(first == last)
            {
                return first;
            }
            ++first;
        }
        return this->end();
    }
};

#endif // CDOUBLYLINKEDLIST_H
