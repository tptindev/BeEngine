#ifndef CTEXTURE2DPOOL_H
#define CTEXTURE2DPOOL_H

#include <unordered_map>
#include "ATexturePool.h"

class SDL_Texture;
class CTexture2DPool: public ATexturePool
{
private:
    static CTexture2DPool* s_instance;
    CTexture2DPool();
    std::unordered_map<const char*, SDL_Texture*> m_textures;

public:
    CTexture2DPool(CTexture2DPool &&) = delete;
    CTexture2DPool &operator=(CTexture2DPool &&) = delete;
    CTexture2DPool(CTexture2DPool &other) = delete;
    void operator=(const CTexture2DPool &) = delete;
    ~CTexture2DPool();
    static CTexture2DPool *instance();

    bool load(const char *id, const char *src);
    void remove(const char *id);
};

#endif // CTEXTURE2DPOOL_H
