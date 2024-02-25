#include "CLayer.h"
#include <CEventDispatcher.h>
#include <CEventReceiver.h>
#include <SDL_events.h>

CLayer::CLayer(CApplication* app)
    :m_app(app)
{

}

bool CLayer::handleEvent(const SDL_Event* event)
{
    for (const auto Handler : m_receivers) {
        if (Handler->handleEvent(event)) {
            return true;
        }
    }
    return false;
}

void CLayer::subscribeToEvents(AEventReceiver *receiver)
{
    m_receivers.push_back(receiver);
}
