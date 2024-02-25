#include "CEventDispatcher.h"
#include <LoggerDefines.h>

CEventDispatcher *CEventDispatcher::s_instance = nullptr;
CEventDispatcher::CEventDispatcher()
{

}

CEventDispatcher *CEventDispatcher::instance()
{
    return s_instance = (s_instance == nullptr)? new CEventDispatcher():s_instance;
}

bool CEventDispatcher::nextEvent(SDL_Event &event)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if(!m_queue_events.empty())
    {
        event = m_queue_events.front();
        m_queue_events.pop();
        return true;
    }
    return false;
}

void CEventDispatcher::dispatchEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue_events.push(event);
        if(m_event_handlers.find(event.type) != m_event_handlers.end())
        {
            m_event_handlers.at(event.type)(event);
        }
    }
}

void CEventDispatcher::addEventListener(SDL_EventType type, EventHandler handler)
{
    m_event_handlers[static_cast<Uint32>(type)] = handler;
}
