#include "CEngine.h"
#include <LoggerDefines.h>
#include <CMemoryManager.h>

CEngine* CEngine::s_instance = nullptr;
CEngine::CEngine()
    :m_running{nullptr}
{
    _DEBUG("%s", __FUNCTION__);
    m_running = STACK_ALLOC(bool,sizeof(bool));
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

