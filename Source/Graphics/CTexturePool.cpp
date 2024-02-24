#include "CTexturePool.h"
#include "CRenderer.h"
#include <SDL_render.h>
#include <SDL_image.h>
#include <LoggerDefines.h>

CTexturePool* CTexturePool::s_instance = nullptr;
CTexturePool::CTexturePool()
{

}

CTexturePool::~CTexturePool()
{

}

CTexturePool *CTexturePool::instance()
{
    return s_instance = (s_instance == nullptr)? new CTexturePool(): s_instance;
}

bool CTexturePool::load(const char *id, const char *src)
{
    bool status = false;
    if(m_textures.find(id) != m_textures.end())
    {
        status = true;
    }
    else
    {
        _DEBUG("TextureID: %s, Texture Path: %s", id, src);
        if(CRenderer::renderer() == nullptr)
        {
            _DEBUG("RENDERER NULL");
            status = false;
        }

        SDL_Texture *texture = nullptr;
        SDL_Surface *surface = IMG_Load(src);
        if (!surface) {
            _DEBUG("Cant load IMG");
            status = false;
        }
        
        texture = SDL_CreateTextureFromSurface(CRenderer::renderer(), surface);
        SDL_FreeSurface(surface);
        m_textures[id] = texture;
    }

    return status;
}

void CTexturePool::remove(const char *id)
{
    if(m_textures.find(id) != m_textures.end())
    {
        SDL_DestroyTexture(m_textures[id]);
    }
}
