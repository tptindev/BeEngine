#ifndef SNODE_H
#define SNODE_H

template<typename T>
struct SNode
{
    T      data{};
    SNode* previous;
    SNode* next;

    SNode()
    {
        this->next = nullptr;
    }
};
#endif // SNODE_H
