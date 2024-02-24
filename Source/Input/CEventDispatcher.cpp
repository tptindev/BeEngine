#include "CEventDispatcher.h"
#include "CEventReceiver.h"
#include <LoggerDefines.h>

CEventDispatcher *CEventDispatcher::s_instance = nullptr;
CEventDispatcher::CEventDispatcher()
{

}

CEventDispatcher *CEventDispatcher::instance()
{
    return s_instance = (s_instance == nullptr)? new CEventDispatcher():s_instance;
}

void CEventDispatcher::dispatchEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        std::unique_lock<std::mutex> lock(m_mutex);
        if(m_event_handlers.find(event.type) != m_event_handlers.end())
        {
            m_event_handlers.at(event.type)(event);
        }

        while (!m_receivers.empty()) {
            m_receivers.front()->handleEvent(&event);
            m_receivers.pop();
        }
    }
}

void CEventDispatcher::addEventListener(SDL_EventType type, EventHandler handler)
{
    m_event_handlers[static_cast<Uint32>(type)] = handler;
}

void CEventDispatcher::addReceiver(CEventReceiver *receiver)
{
    m_receivers.push(receiver);
}

