#ifndef CDOUBLYLINKEDLIST_H
#define CDOUBLYLINKEDLIST_H

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
        SNode<T>* el = new SNode<T>(T(std::forward<TArgs>(args)...));
        if(this->empty())
        {
            this->m_head = el;
        }
        else
        {
            this->m_head->pre = el;
            el->next = this->m_head;
            this->m_head = el;
        }
        this->m_count++;
    }

    template<class ...TArgs>
    void emplace_back(TArgs&& ...args)
    {
        SNode<T>* el = new SNode<T>(T(std::forward<TArgs>(args)...));
        if(this->empty())
        {
            this->m_head = el;
        }
        else
        {
            if(this->m_tail == nullptr)
            {
                this->m_tail = el;
                this->m_tail->pre = this->m_head;
                this->m_head->next = this->m_tail;
            }
            else
            {
                el->pre = this->m_tail;
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
            this->m_head->pre = el;
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
                this->m_tail->pre = this->m_head;
                this->m_head->next = this->m_tail;
            }
            else
            {
                el->pre = this->m_tail;
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
        safeRelease(this->m_head->pre);
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
            this->m_count = 1;
            safeRelease(this->m_head);
        }
        else
        {
            this->m_tail = this->m_tail->pre;
            safeRelease(this->m_tail->next);
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
                if(it == this->begin())
                {
                    this->m_head = this->m_head->next;
                    this->m_head->pre = nullptr;
                }
                else
                {
                    if(it == this->end())
                    {
                        this->pop_back();
                    }
                    else
                    {
                        it->pre->next = it->next;
                        it->next->pre = it->pre;
                        safeRelease(it.data());
                    }
                }

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
