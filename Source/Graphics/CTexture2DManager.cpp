#include "CTexture2DManager.h"

CTexture2DManager* CTexture2DManager::s_instance = nullptr;
CTexture2DManager::CTexture2DManager()
{

}

CTexture2DManager::~CTexture2DManager()
{

}

CTexture2DManager *CTexture2DManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CTexture2DManager(): s_instance;
}

void CTexture2DManager::loadTexture(const char *id, const char *src)
{

}
