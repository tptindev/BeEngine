#include "CButton.h"
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_surface.h>
#include <SDL_pixels.h>
#include <SDL_ttf.h>
#include <LoggerDefines.h>
#include "CPainter.h"

CButton::CButton(CApplication* app, CObject *parent) : CWidget(parent), m_app(app), m_window_Surface(app->windowSurface())
{

}

CSignal<void, CButton::E_BTN_STATE> &CButton::stateChanged()
{
    return m_state_changed;
}

bool CTextButton::handleEvent(const SDL_Event *event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN &&
        event->button.button == SDL_BUTTON_LEFT &&
        isHovered)
    {
        stateChanged().emit(E_BTN_STATE::CLICKED);
    }
    else if (event->type == SDL_MOUSEMOTION)
    {
        if (isHovered != IsWithinBounds(event->motion.x, event->motion.y))
        {
            isHovered = !isHovered;
            update();
        }
        stateChanged().emit(isHovered? E_BTN_STATE::HOVERED: E_BTN_STATE::NORMAL);
        return isHovered;
    }
    return false;
}

void CTextButton::init()
{
    m_current_color = BGColor;
}

void CTextButton::update()
{
    m_current_color = ( isHovered ? HoverColor : BGColor );
}

void CTextButton::render()
{
    CPainter painter(m_app->window());
    painter.drawRect(x(),
                     y(),
                     width(),
                     height(),
                     m_current_color.r,
                     m_current_color.g,
                     m_current_color.b,
                     m_current_color.a);
    painter.drawText(m_text, x() + (width() / 2), y() + (height()/2));

}

bool CTextButton::IsWithinBounds(int _x, int _y)
{
    // Too far left
    if (_x < x()) return false;

    // Too far right
    if (_x > x() + width()) return false;

    // Too high
    if (_y < y()) return false;

    // Too low
    if (_y > y() + height()) return false;

    // Inside rectangle
    return true;
}

CTextButton::CTextButton(CApplication *app, const char* text, CObject *parent) : CButton(app, parent), m_text(text)
{
}
