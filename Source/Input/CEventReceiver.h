#ifndef CEVENTRECEIVER_H
#define CEVENTRECEIVER_H

#include <CObject.h>
#include <SDL_events.h>

class AEventReceiver
{
public:
    virtual bool handleEvent(const SDL_Event* event);
};

#endif // CEVENTRECEIVER_H
