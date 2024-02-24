#include "CSDLWindow.h"
#include <SDL.h>
#include <SDL_image.h>

CSDLWindow::CSDLWindow(CObject *parent): CObject(parent)
{
    m_title = "Undefined";
    m_width = 720;
    m_height = 480;

    initialize();
}

CSDLWindow::CSDLWindow(const char *title, int width, int height, CObject *parent) : CObject(parent)
{
    m_title = title;
    m_width = width;
    m_height = height;

    initialize();
}

CSDLWindow::~CSDLWindow()
{

}

void CSDLWindow::initialize()
{
    _DEBUG("Window Init");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        _DEBUG("Unable to initialize SDL: %s", SDL_GetError());
        return;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        _DEBUG("Unable to initialize SDL Image: %s", SDL_GetError());
        return;
    }

    m_sdl_window = SDL_CreateWindow(title(),
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    width(),
                                    height(),
                                    SDL_WINDOW_SHOWN);

    if (m_sdl_window == nullptr)
    {
        // In the case that the window could not be made...
        _DEBUG("Could not create window: %s", SDL_GetError());

        return;
    }

    _DEBUG("Window size: %d, %d", width(), height());
}

SDL_Window *CSDLWindow::sdlWindow()
{
    return m_sdl_window;
}

SDL_Surface *CSDLWindow::sdlSurface()
{
    return m_sdl_window_surface;
}

void CSDLWindow::update_window_surface()
{
    SDL_UpdateWindowSurface(m_sdl_window);
}

void CSDLWindow::toggleIsFull()
{
    m_is_full = !m_is_full;
    SDL_SetWindowFullscreen(m_sdl_window, (m_is_full? SDL_WINDOW_FULLSCREEN_DESKTOP: 0));
}

