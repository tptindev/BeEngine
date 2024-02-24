#ifndef CEVENTRECEIVER_H
#define CEVENTRECEIVER_H

#include <CObject.h>
#include <SDL_events.h>

class CEventReceiver : public CObject
{
public:
    CEventReceiver(CObject *parent = nullptr);

    virtual bool handleEvent(const SDL_Event* event);
};

#endif // CEVENTRECEIVER_H
