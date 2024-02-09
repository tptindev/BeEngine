#ifndef CNOTIFYDISPATCHER_H
#define CNOTIFYDISPATCHER_H

#include <stdint.h>
#include <unordered_map>

class CNotifyDispatcher
{
private:
    static CNotifyDispatcher* s_instance;
    CNotifyDispatcher();
    ~CNotifyDispatcher();

    std::unordered_map<uint8_t, void(*)> m_observers;

public:
    CNotifyDispatcher(CNotifyDispatcher &&) = delete;
    CNotifyDispatcher &operator=(CNotifyDispatcher &&) = delete;
    CNotifyDispatcher(CNotifyDispatcher &other) = delete;
    void operator=(const CNotifyDispatcher &) = delete;
    static CNotifyDispatcher *instance();

    template <typename T, typename... Args>
    bool notify(uint8_t id, Args &&...args) // signal
    {
    }
};

#endif // CNOTIFYDISPATCHER_H
