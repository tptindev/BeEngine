#ifndef SNODE_H
#define SNODE_H

#include <stdio.h>
#include <utility>

template<typename T>
struct SNode
{
    T      data{};
    SNode* previous;
    SNode* next;

    SNode()
    {
        this->previous  = nullptr;
        this->next      = nullptr;
    }

    SNode(T&& data, SNode* next)
    {
        this->data     = std::move(data);
        this->previous = nullptr;
        this->next     = next;
    }

    SNode(T data, SNode* next)
    {
        this->data     = data;
        this->previous = nullptr;
        this->next     = next;
    }

    SNode(T data, SNode* pre = nullptr, SNode* next = nullptr)
    {
        this->data     = data;
        this->previous = pre;
        this->next     = next;
    }
};
#endif // SNODE_H
