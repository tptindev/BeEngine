#ifndef CMOVEMENTSYSTEM_H
#define CMOVEMENTSYSTEM_H


#include "AECSystem.h"


class CMovementSystem: public AECSystem
{
public:
    CMovementSystem();

//    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};


#endif // CMOVEMENTSYSTEM_H
