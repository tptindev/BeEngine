#ifndef CTEXTUREPOOL_H
#define CTEXTUREPOOL_H

#include <unordered_map>

class SDL_Texture;
class CTexturePool
{
private:
    static CTexturePool* s_instance;
    CTexturePool();
    std::unordered_map<const char*, SDL_Texture*> m_textures;

public:
    CTexturePool(CTexturePool &&) = delete;
    CTexturePool &operator=(CTexturePool &&) = delete;
    CTexturePool(CTexturePool &other) = delete;
    void operator=(const CTexturePool &) = delete;
    ~CTexturePool();
    static CTexturePool *instance();

    bool load(const char *id, const char *src);
    void remove(const char *id);
};

#endif // CTEXTUREPOOL_H
