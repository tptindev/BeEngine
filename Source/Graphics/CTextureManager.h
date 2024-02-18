#ifndef CTEXTUREMANAGER_H
#define CTEXTUREMANAGER_H


class CTextureManager
{
private:
    static CTextureManager* s_instance;
    CTextureManager();
    ~CTextureManager();


public:
    CTextureManager(const CTextureManager &) = delete;
    CTextureManager(CTextureManager &&) = delete;
    CTextureManager &operator=(const CTextureManager &) = delete;
    CTextureManager &operator=(CTextureManager &&) = delete;
    static CTextureManager *instance();
};

#endif // CTEXTUREMANAGER_H
