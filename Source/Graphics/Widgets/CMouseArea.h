#ifndef CMOUSEAREA_H
#define CMOUSEAREA_H

#include <CEventReceiver.h>

class CMouseArea : public CEventReceiver
{
public:
    CMouseArea(CObject *parent = nullptr);

    // CEventReceiver interface
public:
    virtual bool handleEvent(const SDL_Event *event) override;
};

#endif // CMOUSEAREA_H
