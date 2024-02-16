#ifndef CSPAWNSYSTEM_H
#define CSPAWNSYSTEM_H


#include "AECSystem.h"


class CSpawnSystem: public AECSystem
{
public:
    CSpawnSystem();
    //    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};


#endif // CSPAWNSYSTEM_H
