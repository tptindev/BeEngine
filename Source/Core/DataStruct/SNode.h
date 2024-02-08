#ifndef SNODE_H
#define SNODE_H

#include <stdio.h>
#include <utility>

template<typename T, typename ...Args>
struct SNode
{
    T      data{};
    SNode* pre;
    SNode* next;

    SNode()
    {
        this->pre  = nullptr;
        this->next = nullptr;
    }

    SNode(const T& data)
    {
        this->data = std::move(data);
        this->pre  = nullptr;
        this->next = nullptr;
    }

    SNode(T&& data)
    {
        this->data = data;
        this->pre  = nullptr;
        this->next = nullptr;
    }

    SNode(SNode<T>* pre, SNode<T>* next, const T& data)
    {
        this->data = std::move(data);
        this->pre  = pre;
        this->next = next;
    }
};
#endif // SNODE_H
