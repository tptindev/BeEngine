#include "CButton.h"
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_surface.h>
#include <SDL_pixels.h>
#include <LoggerDefines.h>
#include "CPainter.h"

CButton::CButton(CApplication* app, CObject *parent) : CWidget(parent), m_app(app), m_window_Surface(app->windowSurface())
{

}

bool CTextButton::handleEvent(const SDL_Event *event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN &&
        event->button.button == SDL_BUTTON_LEFT &&
        isHovered)
    {
        m_app->quit();
    }
    else if (event->type == SDL_MOUSEMOTION)
    {
        if (isHovered != IsWithinBounds(event->motion.x, event->motion.y))
        {
            isHovered = !isHovered;
            update();
        }
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
    painter.drawRect(m_area.x,
                     m_area.y,
                     m_area.w,
                     m_area.h,
                     m_current_color.r,
                     m_current_color.g,
                     m_current_color.b,
                     m_current_color.a);
}

bool CTextButton::IsWithinBounds(int x, int y)
{
    // Too far left
    if (x < m_area.x) return false;

    // Too far right
    if (x > m_area.x + m_area.w) return false;

    // Too high
    if (y < m_area.y) return false;

    // Too low
    if (y > m_area.y + m_area.h) return false;

    // Inside rectangle
    return true;
}

CTextButton::CTextButton(CApplication *app, CObject *parent) : CButton(app, parent)
{
}
