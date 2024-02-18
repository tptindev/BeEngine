#ifndef CTEXTURE3DPOOL_H
#define CTEXTURE3DPOOL_H

#include "ATexturePool.h"

class CTexture3DPool : public ATexturePool
{
public:
    CTexture3DPool();

    // ATexturePool interface
public:
    virtual bool load(const char *id, const char *src) override;
    virtual void remove(const char *id) override;
};

#endif // CTEXTURE3DPOOL_H
