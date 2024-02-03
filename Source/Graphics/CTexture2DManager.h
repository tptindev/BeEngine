#ifndef CTEXTURE2DMANAGER_H
#define CTEXTURE2DMANAGER_H


class CTexture2DManager
{
private:
    static CTexture2DManager* s_instance;
    CTexture2DManager();

public:
    CTexture2DManager(CTexture2DManager &other) = delete;
    void operator=(const CTexture2DManager &) = delete;
    ~CTexture2DManager();
    static CTexture2DManager* instance();

    void loadTexture(const char* id, const char* src);
//    void drawTile();
//    void drawSprite();
};

#endif // CTEXTURE2DMANAGER_H
