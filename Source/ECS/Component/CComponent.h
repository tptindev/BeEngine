#ifndef CCOMPONENT_H
#define CCOMPONENT_H

#include <Alias.h>
#include <CObject.h>


class CComponent: public CObject
{
private:
    const char* m_name;
    ComponentID                 m_id{MIN_COMPONENT_ID};

public:
    CComponent(const char*);
    ~CComponent();

    ComponentID id() const;
    void setId(const ComponentID &newId);
    const char *name() const;
    void setName(const char *newName);
};


#endif // CCOMPONENT_H
