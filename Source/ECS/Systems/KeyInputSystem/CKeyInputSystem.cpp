#include "CKeyInputSystem.h"
#include "CEntity.h"
#include "ComponentDef/SKeyInputComponent.h"


CKeyInputSystem::CKeyInputSystem()
{
}

CKeyInputSystem::~CKeyInputSystem()
{
    _DEBUG("Release Instance CKeyInputSystem At address [%p]", this);
}

void CKeyInputSystem::init(CEntity *entity)
{
    UNUSED(entity)
}

void CKeyInputSystem::update(CEntity *entity, float dt)
{
    UNUSED(dt)
}



