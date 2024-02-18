#ifndef CEVENTDISPATCHER_H
#define CEVENTDISPATCHER_H

#include <SDL_events.h>
#include <mutex>
#include <functional>
#include <unordered_map>

typedef std::function<void(SDL_Event&)> EventHandler;
class CEventDispatcher
{
private:
    CEventDispatcher();
    static CEventDispatcher *s_instance;

    std::mutex              m_mutex;
    std::unordered_map<Uint32, EventHandler> m_event_handlers;
public:
    CEventDispatcher(const CEventDispatcher &) = delete;
    CEventDispatcher(CEventDispatcher &&) = delete;
    CEventDispatcher &operator=(const CEventDispatcher &) = delete;
    CEventDispatcher &operator=(CEventDispatcher &&) = delete;
    static CEventDispatcher *instance();

    void dispatchEvent();
    void addEventListener(SDL_EventType, EventHandler);
};
#endif // CEVENTDISPATCHER_H
