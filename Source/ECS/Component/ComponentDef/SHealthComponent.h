#ifndef SHEALTHCOMPONENT_H
#define SHEALTHCOMPONENT_H


#include "CComponent.h"


struct SHealthComponent: public CComponent
{
    SHealthComponent(float max): CComponent(__FUNCTION__), max(max)
    {
    }
    float current, max;
};


#endif // SHEALTHCOMPONENT_H
