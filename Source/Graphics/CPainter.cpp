#include "CPainter.h"
#include <SDL_render.h>
#include <SDL_ttf.h>
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

void CPainter::drawText(const char* text, int x, int y)
{
    if(text != nullptr)
    {
        SDL_Surface* surface = nullptr;
        SDL_Texture* texture = nullptr;
        TTF_Font* font = nullptr;
        SDL_Color Color = {20, 20, 20};
        font = TTF_OpenFont("./Resources/Font/Roboto/Roboto-Medium.ttf", 24);

        if(font == nullptr) {
            _DEBUG("TTF_OpenFont: %s\n", TTF_GetError());
            return;
        }

        surface = TTF_RenderUTF8_Blended(font, text, Color);
        if(surface == nullptr)
        {
            _DEBUG("Failed to create text surface: %s", TTF_GetError());
            return;
        }
        else
        {
            texture = SDL_CreateTextureFromSurface(m_window->sdlRenderer(), surface);
            if(texture == nullptr)
            {
                _DEBUG("Failed to create text texture: %s", SDL_GetError());
                return;
            }
        }

        SDL_Rect Source { 0, 0, surface->w, surface->h };
        SDL_Rect Destination { x - Source.w/2, y - Source.h/2, Source.w, Source.h };
        SDL_RenderCopy(m_window->sdlRenderer(), texture, &Source, &Destination);
        TTF_CloseFont(font);
        font = NULL;
    }
    else
    {
        _DEBUG("Text is NULL");
    }
}
