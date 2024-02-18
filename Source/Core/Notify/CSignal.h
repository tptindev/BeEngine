#ifndef CSignal_H
#define CSignal_H

#include <stdint.h>
#include <vector>
#include <functional>
#include <LoggerDefines.h>

template<typename Ret, typename ...Args>
class CSignal
{
public:
    typedef std::function<Ret(Args...)> SlotType;

public:
    CSignal()
    {
        _DEBUG("%s [%p]", __FUNCTION__, this);
    }
    ~CSignal()
    {
        _DEBUG("%s [%p]", __FUNCTION__, this);
    }

    bool connect(const SlotType& slot)
    {
        _DEBUG("CONNECT SLOT [%p] -> SIGNAL [%p]", &slot, this);
        typename std::vector<SlotType>::iterator it = m_slots.begin();
        while (it != m_slots.end())
        {
            if(&(*it) == &slot) return false;
            ++it;
        }
        m_slots.push_back(slot);
        return true;
    }

    void emit(Args&&... args)
    {
        _DEBUG("EMIT SIGNAL [%p]", this);
        for (const auto& slot :m_slots)
        {
            slot(args...);
        }
    }

private:
    std::vector<SlotType> m_slots;

};

#endif // CSignal_H
