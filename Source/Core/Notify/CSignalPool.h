#ifndef CSIGNALPOOL_H
#define CSIGNALPOOL_H

#include <stdint.h>
#include <unordered_map>
#include <functional>
#include <IObserver.h>
#include "CDoublyLinkedList.h"

class CSignalPool
{
private:
    static CSignalPool* s_instance;
    CSignalPool();
    ~CSignalPool();

    std::unordered_map<const char*, std::function<void(void)>> m_signals;

public:
    CSignalPool(CSignalPool &&) = delete;
    CSignalPool &operator=(CSignalPool &&) = delete;
    CSignalPool(CSignalPool &other) = delete;
    void operator=(const CSignalPool &) = delete;
    static CSignalPool *instance();

    template<typename Ret, typename ...Args>
    bool signal_wrapper(uint8_t, Args&&... args)
    {
        auto func = [](Args&&... args) -> Ret {

        };



    }

//    bool connect(uint8_t signal, IObserver* observer);
    //    bool notify(uint8_t signal, void* data); // signal
};

#endif // CSIGNALPOOL_H
