#ifndef CBUTTON_H
#define CBUTTON_H

#include <unordered_map>
#include "CApplication.h"
#include "CWidget.h"
#include "CEventReceiver.h"

class SDL_Texture;
class CButton : public CWidget, public AEventReceiver
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

    CButton(CApplication* app, CObject *parent = nullptr);

protected:
    CApplication* m_app { nullptr };
    SDL_Surface* m_window_Surface { nullptr };

    // CWidget interface
public:
    virtual void init() override {}
    virtual void update() override {}
    virtual void render() override {}
};

class CTextButton: public CButton
{
    // CEventReceiver interface
public:
    CTextButton(CApplication *app, const char* text, CObject *parent = nullptr);

    virtual bool handleEvent(const SDL_Event *event) override;

    // CButton interface
public:
    virtual void init() override;
    virtual void update() override;
    virtual void render() override;

private:
    bool isHovered { false };
    SDL_Color BGColor { 255, 50, 50, 255 };
    SDL_Color HoverColor { 50, 50, 255, 255 };
    SDL_Color m_current_color;
    const char* m_text;


    bool IsWithinBounds(int x, int y);
};

#endif // CBUTTON_H
