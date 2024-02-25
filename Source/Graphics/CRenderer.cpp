#include "CRenderer.h"
#include <LoggerDefines.h>
#include <SDL_render.h>
#include "Widgets/CWindow.h"
#include <SDL.h>
#include <SDL_image.h>

CRenderer *CRenderer::s_instance = nullptr;
CRenderer::CRenderer()
{

}

CRenderer *CRenderer::instance()
{
    return s_instance = (s_instance == nullptr)? new CRenderer(): s_instance;
}

bool CRenderer::initialize(CWindow* window)
{
    m_window = window;
    m_renderer = m_window->sdlRenderer();
    return (m_window != nullptr && m_renderer != nullptr);
}

bool CRenderer::destroy()
{
    SDL_DestroyRenderer(m_renderer);
    return (m_renderer == nullptr);
}

void CRenderer::beginDraw()
{
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderClear(m_renderer);
}

void CRenderer::endDraw()
{
    SDL_RenderPresent(m_renderer);
}

