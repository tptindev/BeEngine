#ifndef CCAMERASYSTEM_H
#define CCAMERASYSTEM_H

#include "AECSystem.h"


class CEntity;
class CCameraSystem: public AECSystem
{
public:
    CCameraSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};


#endif // CCAMERASYSTEM_H
