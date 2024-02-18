#include "CRenderer2D.h"
#include <LoggerDefines.h>
#include <SDL_render.h>
#include "Widgets/CWindow.h"
#include <SDL.h>
#include <SDL_image.h>

CRenderer2D *CRenderer2D::s_instance = nullptr;
SDL_Renderer* CRenderer2D::s_renderer = nullptr;
CRenderer2D::CRenderer2D()
{

}

CRenderer2D *CRenderer2D::instance()
{
    return s_instance = (s_instance == nullptr)? new CRenderer2D(): s_instance;
}

SDL_Renderer *CRenderer2D::renderer()
{
    return s_renderer;
}

void CRenderer2D::initialize()
{

}

bool CRenderer2D::ready()
{
    _DEBUG("Game Init");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        _DEBUG("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        _DEBUG("Unable to initialize SDL Image: %s", SDL_GetError());
        return false;
    }

    return true;
}

bool CRenderer2D::openWindow(CWindow* window)
{
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    UNUSED(window_flags)

    m_window = SDL_CreateWindow(window->title(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window->width(), window->height(), SDL_WINDOW_SHOWN);

    if (m_window == nullptr)
    {
        // In the case that the window could not be made...
        _DEBUG("Could not create window: %s", SDL_GetError());

        return false;
    }

    _DEBUG("Window size: %d, %d", window->width(), window->height());

    s_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (s_renderer == nullptr)
    {
        _DEBUG("Could not create renderer: %s", SDL_GetError());
        return false;
    }

    window->stateChanged().connect([&](bool isFull) ->void {
        SDL_SetWindowFullscreen(m_window, (isFull? SDL_WINDOW_FULLSCREEN_DESKTOP: 0));
    });

    return true;
}

bool CRenderer2D::destroyWindow()
{
    SDL_DestroyRenderer(s_renderer);
    SDL_DestroyWindow(m_window);
    return (s_renderer == nullptr && m_window == nullptr);
}

void CRenderer2D::quit()
{
    IMG_Quit();
    SDL_Quit();
}

void CRenderer2D::beginDraw()
{
    SDL_SetRenderDrawColor(s_renderer, 0, 0, 0, 255);
    SDL_RenderClear(s_renderer);
}

void CRenderer2D::endDraw()
{
    SDL_RenderPresent(s_renderer);
}

