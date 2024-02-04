#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

class ILinkedList
{
public:
    virtual void push_back() {}
    virtual void pop_back() {}
    virtual bool empty() = 0;
};

#endif // ILINKEDLIST_H
