#include "CEngine.h"

CEngine* CEngine::s_instance = nullptr;
CEngine::CEngine()
{
}

CEngine::~CEngine()
{
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

