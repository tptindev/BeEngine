#include "CPainter.h"
#include <SDL_render.h>
#include <Widgets/CWindow.h>

CPainter::CPainter(CWindow* window)
    :m_window(window)
{

}
void CPainter::drawRect(int x, int y, int width, int height, int r, int g, int b, int a)
{
    SDL_Rect rect{x, y, width, height};
    SDL_SetRenderDrawColor(m_window->sdlRenderer(), r, g, b, a);
    SDL_RenderDrawRect(m_window->sdlRenderer(), &rect);
    SDL_RenderFillRect(m_window->sdlRenderer(), &rect);
}
