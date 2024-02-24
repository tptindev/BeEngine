#include "CRenderer.h"
#include <LoggerDefines.h>
#include <SDL_render.h>
#include "Widgets/CWindow.h"
#include <SDL.h>
#include <SDL_image.h>

CRenderer *CRenderer::s_instance = nullptr;
SDL_Renderer* CRenderer::s_renderer = nullptr;
CRenderer::CRenderer()
{

}

CRenderer *CRenderer::instance()
{
    return s_instance = (s_instance == nullptr)? new CRenderer(): s_instance;
}

SDL_Renderer *CRenderer::renderer()
{
    return s_renderer;
}

void CRenderer::initialize()
{

}

bool CRenderer::openWindow(CWindow* window)
{
    if (window == nullptr)
    {
        // In the case that the window could not be made...
        _DEBUG("Window is NULL");

        return false;
    }

    s_renderer = SDL_CreateRenderer(dynamic_cast<CWindow*>(window)->sdlWindow(), -1, SDL_RENDERER_ACCELERATED);
    if (s_renderer == nullptr)
    {
        _DEBUG("Could not create renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

bool CRenderer::destroyRenderer()
{
    SDL_DestroyRenderer(s_renderer);
    return (s_renderer == nullptr);
}

void CRenderer::beginDraw()
{
    SDL_SetRenderDrawColor(s_renderer, 255, 255, 255, 255);
    SDL_RenderClear(s_renderer);
}

void CRenderer::endDraw()
{
    SDL_RenderPresent(s_renderer);
}

