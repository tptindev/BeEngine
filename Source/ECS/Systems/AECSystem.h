#ifndef AECSYSTEM_H
#define AECSYSTEM_H

class CEntity;
class AECSystem
{
public:
    virtual void init(CEntity *entity) = 0;
    virtual void update(CEntity *entity, float dt) = 0;
};


#endif // AECSYSTEM_H
