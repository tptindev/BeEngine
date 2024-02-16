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

    SNode(const T& data)
    {
        this->data = std::move(data);
        this->pre  = nullptr;
        this->next = nullptr;
    }
};
#endif // SNODE_H
