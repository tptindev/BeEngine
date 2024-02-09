#include "CNotifyDispatcher.h"

CNotifyDispatcher *CNotifyDispatcher::s_instance = nullptr;
CNotifyDispatcher::CNotifyDispatcher()
{

}

CNotifyDispatcher::~CNotifyDispatcher()
{

}

CNotifyDispatcher *CNotifyDispatcher::instance()
{
    return s_instance = (s_instance == nullptr)? new CNotifyDispatcher: s_instance;

}
