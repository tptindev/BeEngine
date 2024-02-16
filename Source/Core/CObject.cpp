#include "CObject.h"
#include <Utils.h>

CObject::CObject(CObject *parent)
{
    if(parent != nullptr)
    {
        parent->m_childs.push_back(this);
    }
}

CObject::~CObject()
{
    CDoublyLinkedList<CObject*>::iterator it = this->m_childs.begin();
    while (it != this->m_childs.end())
    {
        safeRelease((*it));
        ++it;
    }
}
