#include "CComponent.h"

CComponent::CComponent(const char* name)
    : m_name(name)
{
}

CComponent::~CComponent()
{
}

ComponentID CComponent::id() const
{
    return m_id;
}

void CComponent::setId(const ComponentID &newId)
{
    m_id = newId;
}

const char *CComponent::name() const
{
    return m_name;
}



