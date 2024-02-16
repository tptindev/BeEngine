#ifndef CMOTIONSYSTEM_H
#define CMOTIONSYSTEM_H

#include "AECSystem.h"


class CMotionSystem: public AECSystem
{
public:
    CMotionSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};


#endif // CMOTIONSYSTEM_H
