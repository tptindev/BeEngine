#include "CEventReceiver.h"

CEventReceiver::CEventReceiver(CObject *parent) : CObject(parent)
{}

bool CEventReceiver::handleEvent(const SDL_Event*event)
{
    return false;
}
