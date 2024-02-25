#ifndef CBUTTON_H
#define CBUTTON_H

#include <unordered_map>
#include <CSignal.h>
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
        PRESSED,
        PRESS_AND_HOLD,
        CLICKED,
        RELEASED,
        HOVERED,
        IN_ACTIVE
    };

    CButton(CApplication* app, CObject *parent = nullptr);
    CSignal<void, E_BTN_STATE>& stateChanged();

protected:
    CApplication* m_app { nullptr };
    SDL_Surface* m_window_Surface { nullptr };

private:
    CSignal<void, E_BTN_STATE> m_state_changed;

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
