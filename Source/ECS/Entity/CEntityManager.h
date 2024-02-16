#ifndef CENTITYMANAGER_H
#define CENTITYMANAGER_H

#include "CEntity.h"


class CEntityManager
{
private:
    CEntityManager();

    static CEntityManager                   *s_instance;
    EntityID                                m_entity_count{MIN_ENTITY_COUNT};
    std::queue<EntityID>                    m_available_ids;
    std::vector<CEntity*>                   m_entities;
public:
    static CEntityManager *instance();

    bool createEntity(CEntity*);
    bool destroyEntity(CEntity*);
    std::vector<CEntity *> entities() const;
};


#endif // CENTITYMANAGER_H
