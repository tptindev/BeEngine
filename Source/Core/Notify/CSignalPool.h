#ifndef CSIGNALPOOL_H
#define CSIGNALPOOL_H

#include <stdint.h>
#include <unordered_map>
#include <IObserver.h>
#include "CDoublyLinkedList.h"

class CSignalPool
{
private:
    static CSignalPool* s_instance;
    CSignalPool();
    ~CSignalPool();

    std::unordered_map<uint8_t, CDoublyLinkedList<IObserver*>> m_observers;

public:
    CSignalPool(CSignalPool &&) = delete;
    CSignalPool &operator=(CSignalPool &&) = delete;
    CSignalPool(CSignalPool &other) = delete;
    void operator=(const CSignalPool &) = delete;
    static CSignalPool *instance();

    bool connect(uint8_t signal, IObserver* observer);
    bool notify(uint8_t signal, void* data); // signal
};

#endif // CSIGNALPOOL_H
