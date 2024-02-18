#ifndef ATEXTUREPOOL_H
#define ATEXTUREPOOL_H


class ATexturePool
{
public:
    virtual bool load(const char *id, const char *src) = 0;
    virtual void remove(const char *id) = 0;
};

#endif // ATEXTUREPOOL_H
