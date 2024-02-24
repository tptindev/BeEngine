#include "CLayer.h"
#include "CEventDispatcher.h"

CLayer::CLayer()
    :m_dispatcher(CEventDispatcher::instance())
{

}

void CLayer::subcribeToEvent(CEventReceiver *receiver)
{
    m_dispatcher->addReceiver(receiver);
}
