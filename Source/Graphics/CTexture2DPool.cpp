#include "CTexture2DPool.h"
#include "CRenderer2D.h"
#include <SDL_render.h>
#include <SDL_image.h>
#include <LoggerDefines.h>

CTexture2DPool* CTexture2DPool::s_instance = nullptr;
CTexture2DPool::CTexture2DPool()
{

}

CTexture2DPool::~CTexture2DPool()
{

}

CTexture2DPool *CTexture2DPool::instance()
{
    return s_instance = (s_instance == nullptr)? new CTexture2DPool(): s_instance;
}

bool CTexture2DPool::load(const char *id, const char *src)
{
    bool status = false;
    if(m_textures.find(id) != m_textures.end())
    {
        status = true;
    }
    else
    {
        _DEBUG("TextureID: %s, Texture Path: %s", id, src);
        if(CRenderer2D::renderer() == nullptr)
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

        texture = SDL_CreateTextureFromSurface(CRenderer2D::renderer(), surface);
        SDL_FreeSurface(surface);
        m_textures[id] = texture;
    }

    return status;
}

void CTexture2DPool::remove(const char *id)
{
    if(m_textures.find(id) != m_textures.end())
    {
        SDL_DestroyTexture(m_textures[id]);
    }
}
