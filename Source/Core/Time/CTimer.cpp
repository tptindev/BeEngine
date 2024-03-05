#include "CTimer.h"
#include <stdio.h>

CTimer::CTimer()
    :m_time_point(std::chrono::high_resolution_clock::now())
{
}
