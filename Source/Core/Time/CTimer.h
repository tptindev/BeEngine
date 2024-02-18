#ifndef CTIMER_H
#define CTIMER_H

#include <chrono>

class CTimer
{
    typedef std::chrono::time_point<std::chrono::high_resolution_clock> TimePointType;
private:
    TimePointType m_time_point;
public:
    CTimer();

    inline void reset() { m_time_point = std::chrono::high_resolution_clock::now(); }

    // Get elapsed time in milliseconds
    long long elapsed_milliseconds() const {
        TimePointType endTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_time_point).count();
    }

    // Get elapsed time in seconds
    double elapsed_seconds() const {
        return elapsed_milliseconds() / 1000.0;
    }

    // Get elapsed time in minutes
    double elapsed_minutes() const {
        return elapsed_seconds() / 60.0;
    }

    // Get elapsed time in hours
    double elapsed_hours() const {
        return elapsed_minutes() / 60.0;
    }

    // Get elapsed time in days
    double elapsed_days() const {
        return elapsed_hours() / 24.0;
    }
};

#endif // CTIMER_H
