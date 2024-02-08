#include "CPoolSignals.h"

CPoolSignals* CPoolSignals::s_instance = nullptr;
CPoolSignals::CPoolSignals()
{

}

CPoolSignals *CPoolSignals::instance()
{
    return s_instance = (s_instance == nullptr)? new CPoolSignals(): s_instance;
}
