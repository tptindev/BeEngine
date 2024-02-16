#ifndef CCOMPONENTMANAGER_H
#define CCOMPONENTMANAGER_H

#include <unordered_map>
#include <queue>
#include "CComponent.h"

class CComponentManager
{
private:
    CComponentManager();

    static CComponentManager                        *s_instance;
    ComponentID                                     m_component_count{MIN_COMPONENT_COUNT};
    std::queue<ComponentID>                         m_available_ids;
    std::unordered_map<const char*, ComponentID>    m_dictionary;

public:
    ~CComponentManager();
    static CComponentManager                    *instance();

    bool createComponent(CComponent*);
};


#endif // CCOMPONENTMANAGER_H
