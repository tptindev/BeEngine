#ifndef CENTITY_H
#define CENTITY_H

#include <LoggerDefines.h>
#include <unordered_map>
#include <CObject.h>
#include <assert.h>
#include "Alias.h"
#include "CComponent.h"
#include "CComponentManager.h"

#define COMP_MANAGER CComponentManager::instance()


class CEntity: public CObject
{
private:
    EntityID                                         m_id;
    std::unordered_map<const char*, CComponent*>     m_components;

protected:
    std::mutex                                       m_mutex;

public:
    CEntity();
    virtual ~CEntity(); 

    bool operator==(const CEntity &other) { return this->id() == other.id(); }
    bool operator==(const CEntity *other) { return this->id() == other->id(); }

    EntityID id() const;
    void setId(const EntityID &newId);

    template<class T, typename ...TArgs>
    T *addComponent(TArgs&&...args)
    {
        const char *compName = typeid(T).name();
        assert(m_components.find(compName) == m_components.end() && "Adding component more than once.");

        T *c = new T(std::forward<TArgs>(args)...);
        if(COMP_MANAGER->createComponent(c))
        {
            m_components[compName] = std::move(c);
            return static_cast<T*>(m_components.at(compName));
        }
        return nullptr;
    }

    template<class T>
    bool destroyComponent()
    {
        const char *compName = typeid(T).name();
        auto it = m_components.find(compName);
        if(it == m_components.end())
            return 0;
        m_components.erase(it);
        return 1;
    }

    template<class T>
    T* getComponent() const
    {
        const char *compName = typeid(T).name();
        if(m_components.empty()) return nullptr;
        if(m_components.find(compName) == m_components.end())
        {
            //            _DEBUG("Component [%s]  of Entity [%d] does not exist", compName, this->id());
            return nullptr;
        }
        return static_cast<T*>(m_components.at(compName));
    }

    template<class T>
    bool hasComponent() const
    {
        const char *compName = typeid(T).name();
        if(m_components.find(compName) == m_components.end()) return false;
        if(m_components.at(compName) == nullptr)
        {
            return false;
        }
        return true;
    }

};


#endif // CENTITY_H
