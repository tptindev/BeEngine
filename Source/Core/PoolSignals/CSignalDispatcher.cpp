#include "CSignalDispatcher.h"

CSignalDispatcher* CSignalDispatcher::s_instance = nullptr;
CSignalDispatcher::CSignalDispatcher()
{

}

CSignalDispatcher *CSignalDispatcher::instance()
{
    return s_instance = (s_instance == nullptr)? new CSignalDispatcher(): s_instance;
}
