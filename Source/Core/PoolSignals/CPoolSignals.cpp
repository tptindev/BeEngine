#include "CPoolSignals.h"

CPoolSignals* CPoolSignals::s_instance = nullptr;
CPoolSignals::CPoolSignals()
{
    for (uint8_t id = 0; id < sizeof(uint8_t); ++id) {
        m_ids.push(id);
    }
}

CPoolSignals *CPoolSignals::instance()
{
    return s_instance = (s_instance == nullptr)? new CPoolSignals(): s_instance;
}
