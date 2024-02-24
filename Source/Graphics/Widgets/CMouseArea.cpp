#include "CMouseArea.h"


CMouseArea::CMouseArea(CObject *parent) : CEventReceiver(parent)
{}

bool CMouseArea::handleEvent(const SDL_Event *event)
{
    return false;
}
