#ifndef COBJECT_H
#define COBJECT_H

#include <functional>
#include "CDoublyLinkedList.h"

class CObject
{
private:
    CDoublyLinkedList<CObject*> m_childs;

public:
    explicit CObject(CObject* parent = nullptr);
    ~CObject();
};

#endif // COBJECT_H
