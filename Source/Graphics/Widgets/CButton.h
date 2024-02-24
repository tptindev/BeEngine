#ifndef CBUTTON_H
#define CBUTTON_H

#include "CWidget.h"
#include "CEventReceiver.h"

class SDL_Texture;
class CButton : public CWidget, public CEventReceiver
{
private:
    SDL_Texture* m_texture;


public:
    CButton(const char* src, CObject *parent = nullptr);

    // CEventReceiver interface
public:
    virtual bool handleEvent(const SDL_Event *event) override;
};

#endif // CBUTTON_H
