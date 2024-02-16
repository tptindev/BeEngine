#ifndef CKEYINPUTSYSTEM_H
#define CKEYINPUTSYSTEM_H


#include "AECSystem.h"


class CKeyInputSystem: public AECSystem
{
public:
    CKeyInputSystem();
    ~CKeyInputSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};


#endif // CKEYINPUTSYSTEM_H
