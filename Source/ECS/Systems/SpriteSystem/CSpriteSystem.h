#ifndef CSPRITESYSTEM_H
#define CSPRITESYSTEM_H


#include "AECSystem.h"


class CSpriteSystem: public AECSystem
{
public:
    CSpriteSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};


#endif // CSPRITESYSTEM_H
