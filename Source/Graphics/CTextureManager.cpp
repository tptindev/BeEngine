#include "CTextureManager.h"

CTextureManager *CTextureManager::s_instance = nullptr;
CTextureManager::CTextureManager()
{

}

CTextureManager::~CTextureManager()
{

}

CTextureManager *CTextureManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CTextureManager(): s_instance;
}
