#include "CEngine.h"
#include <LoggerDefines.h>

CEngine* CEngine::s_instance = nullptr;
CEngine::CEngine()
{
    _DEBUG("%s", __FUNCTION__);
}

CEngine::~CEngine()
{
    _DEBUG("%s", __FUNCTION__);
}

CEngine *CEngine::instance()
{
    return s_instance = (s_instance == nullptr)? new CEngine(): s_instance;
}

bool CEngine::initialize()
{
    return true;
}

void CEngine::loop()
{

}

void CEngine::clean()
{

}

void CEngine::quit()
{

}

