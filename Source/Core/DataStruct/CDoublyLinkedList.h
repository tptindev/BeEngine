#ifndef CDOUBLYLINKEDLIST_H
#define CDOUBLYLINKEDLIST_H

#include <Utils.h>
#include "ILinkedList.h"
#include "CIterator.h"
#include "SNode.h"

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

    typedef CIterator<T>  iterator;

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

    CIterator<T> erase(CIterator<T> position)
    {
        iterator it = this->begin();
        while (it != this->end())
        {
            if(it == position)
            {
                if(it->pre != nullptr) it->pre->next = it->next;
                if(it->next != nullptr) it->next->pre = it->pre;
                safeRelease(it.data());
                this->m_count--;
                break;
            }
            ++it;
        }
        return ++it;
    }

    CIterator<T> erase(CIterator<T> first, CIterator<T> last)
    {
        iterator &it = first;
        while (it != last)
        {
            if(it == last)
            {
                // pre
                it->pre->next = it->next;
                // next
                it->next->pre = it->pre;

                this->m_count--;
                break;
            }
            ++it;
        }
        return ++it;
    }
};

#endif // CDOUBLYLINKEDLIST_H
