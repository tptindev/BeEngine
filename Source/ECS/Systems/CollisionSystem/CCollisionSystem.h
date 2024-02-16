#ifndef CCOLLISIONSYSTEM_H
#define CCOLLISIONSYSTEM_H

#include "AECSystem.h"


struct SMotionComponent;
struct SBoxComponent;
class CCollisionSystem: public AECSystem
{
private:

public:
    CCollisionSystem();
    ~CCollisionSystem();

//    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};


#endif // CCOLLISIONSYSTEM_H
