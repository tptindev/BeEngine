#include "CKeyEvent.h"


bool CKeyEvent::handleEvent(const SDL_Event *event)
{
    return false;
}

CKeyEvent::CKeyEvent(CObject *parent) : CEventReceiver(parent)
{}
