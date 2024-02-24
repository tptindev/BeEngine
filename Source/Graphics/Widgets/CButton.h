#ifndef CBUTTON_H
#define CBUTTON_H

#include <unordered_map>
#include "CWidget.h"
#include "CEventReceiver.h"

class SDL_Texture;
class CButton : public CWidget, public CEventReceiver
{
public:
    enum E_BTN_STATE: char
    {
        NORMAL,
        PRESS,
        PRESS_AND_HOLD,
        CLICK,
        RELEASE,
        HOVER,
        IN_ACTIVE
    };

    CButton(CObject *parent = nullptr);

public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

class CTextButton: public CButton
{
    // CEventReceiver interface
public:
    virtual bool handleEvent(const SDL_Event *event) override;

    // CButton interface
public:
    virtual void init() override;
    virtual void update() override;
    virtual void render() override;
};

#endif // CBUTTON_H
