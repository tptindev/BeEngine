#ifndef CSINGLYLINKEDLIST_H
#define CSINGLYLINKEDLIST_H

#include <iostream>
#include <Utils.h>
#include "ILinkedList.h"
#include "SNode.h"

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

    friend std::ostream &operator<<(std::ostream &out, CSinglyLinkedList &list)
    {
        out << "[" << &list << "] Singly Linked List: " << std::endl;
        if(list.empty())
        {
            out << "EMPTY" << std::endl;
        }
        else
        {
            int i = 0;;
            SNode<T> *ptr = list.m_head;
            while (ptr != nullptr) {
                out << "[" << ptr << "][" << i << "][" << ptr->data << "]" << std::endl;
                ptr = ptr->next;
                i++;
            }
        }
        return out;
    }

    T &front()
    {
        return this->m_head->data;
    }

    T &back()
    {
        return this->m_tail->data;
    }

    template<class ...TArgs>
    void emplace_front(TArgs&& ...args)
    {
        SNode<T>* el = new SNode<T>(std::forward<TArgs>(args)...);
        if(empty())
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
        if(empty())
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
        SNode<T>* el = new SNode<T>(data);
        if(empty())
        {
            this->m_head = el;
        }
        else
        {
            el->next = this->m_head;
            this->m_head = el;
        }
    }

    void push_back(T data)
    {
        SNode<T>* el = new SNode<T>(data);
        if(empty())
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

//    template<class ...TArgs>
//    void emplace(TArgs&&...args)
//    {
//        SNode<T>* el = new SNode<T>(std::forward<TArgs>(args)...);

//    }

    bool empty()
    {
        return (this->m_count < 1 && this->m_head == nullptr);
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
