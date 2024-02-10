#include "CSignalPool.h"

CSignalPool *CSignalPool::s_instance = nullptr;
CSignalPool::CSignalPool()
{

}

CSignalPool::~CSignalPool()
{

}

CSignalPool *CSignalPool::instance()
{
    return s_instance = (s_instance == nullptr)? new CSignalPool(): s_instance;
}

bool CSignalPool::connect(uint8_t signal, IObserver *observer)
{
    if(m_observers.find(signal) == m_observers.end())
    {
        m_observers[signal] = CDoublyLinkedList<IObserver*>{observer};
    }
    else
    {
        m_observers[signal].push_back(observer);
    }
    return false;
}

bool CSignalPool::notify(uint8_t signal, void *data)
{
    if(m_observers[signal].empty())
    {
        return false;
    }
    else
    {
        CDoublyLinkedList<IObserver*>::iterator it = m_observers[signal].begin();
        while (it != m_observers[signal].end())
        {
            it->data->onNotify(signal, data);
        }
    }
    return false;
}
