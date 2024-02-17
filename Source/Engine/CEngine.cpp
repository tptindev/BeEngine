#include "CEngine.h"
#include <LoggerDefines.h>
#include <CMemoryManager.h>

CEngine* CEngine::s_instance = nullptr;
CEngine::CEngine(CObject *parent)
    :CObject(parent), m_running(true)
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
    // Get elapsed time
    _DEBUG("Elapsed milliseconds: %lld",m_timer.elapsed_milliseconds());
    _DEBUG("Elapsed seconds: %lf",m_timer.elapsed_seconds());
    _DEBUG("Elapsed minutes: %lf",m_timer.elapsed_minutes());
}

