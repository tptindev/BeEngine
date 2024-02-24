#ifndef CKEYEVENT_H
#define CKEYEVENT_H

#include <CEventReceiver.h>

class CKeyEvent : public CEventReceiver
{
public:
    CKeyEvent(CObject *parent = nullptr);

    // CEventReceiver interface
public:
    virtual bool handleEvent(const SDL_Event *event) override;
};

#endif // CKEYEVENT_H
