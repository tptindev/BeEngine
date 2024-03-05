#include "CWindow.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

CWindow::CWindow(CObject *parent): CObject(parent)
{
    m_title = "Undefined";
    m_width = 720;
    m_height = 480;

    initialize();
}

CWindow::CWindow(const char *title, int width, int height, CObject *parent) : CObject(parent)
{
    m_title = title;
    m_width = width;
    m_height = height;

    initialize();
}

CWindow::~CWindow()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void CWindow::initialize()
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

    if (TTF_Init() < 0)
    {
        _DEBUG("Unable to initialize SDL TTF: %s", SDL_GetError());
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

    m_sdl_window_surface = SDL_GetWindowSurface(m_sdl_window);
    if (m_sdl_window_surface == nullptr)
    {
        // In the case that the window could not be made...
        _DEBUG("Could not get window surface: %s", SDL_GetError());

        return;
    }

    m_sdl_renderer = SDL_CreateRenderer(m_sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_sdl_renderer == nullptr)
    {
        _DEBUG("Could not create renderer: %s", SDL_GetError());
        return;
    }
}

void CWindow::destroy()
{
    SDL_DestroyWindow(m_sdl_window);
    _DEBUG("SDL Window [%p] is Destroyed", m_sdl_window);
}

SDL_Window *CWindow::sdlWindow()
{
    return m_sdl_window;
}

SDL_Surface *CWindow::sdlSurface()
{
    return m_sdl_window_surface;
}

SDL_Renderer *CWindow::sdlRenderer()
{
    return m_sdl_renderer;
}

void CWindow::updateWindowSurface()
{
    SDL_UpdateWindowSurface(m_sdl_window);
}

void CWindow::registerLayer(CLayer *layer)
{
    m_layers.push_front(layer);
}

std::list<CLayer *>& CWindow::layers()
{
    return m_layers;
}

CSignal<void, int, int>& CWindow::windowSizeChanged()
{
    return m_window_size_changed;
}

void CWindow::toggleIsFull()
{
    m_is_full = !m_is_full;
    int status = SDL_SetWindowFullscreen(m_sdl_window, (m_is_full? SDL_WINDOW_FULLSCREEN_DESKTOP: 0));
    if(status == 0)
    {
        SDL_GetWindowSize(m_sdl_window, &m_width, &m_height);
        m_window_size_changed.emit(std::move(m_width), std::move(m_height));
    }
}

const char *CWindow::title() const
{
    return m_title;
}

int CWindow::width() const
{
    return m_width;
}

int CWindow::height() const
{
    return m_height;
}

int CWindow::x() const
{
    return m_x;
}

int CWindow::y() const
{
    return m_y;
}

bool CWindow::is_full() const
{
    return m_is_full;
}

bool CWindow::active() const
{
    return m_active;
}

