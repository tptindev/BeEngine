#ifndef ALIAS_H
#define ALIAS_H

#include <stdint.h>
#include <bitset>

using EntityID      = uint32_t;
using ComponentID   = uint32_t;

const EntityID MIN_ENTITY_COUNT     = 0;
const EntityID MIN_ENTITY_ID        = 0;
const EntityID MAX_ENTITY_ID        = 50;

const ComponentID MIN_COMPONENT_COUNT       = 0;
const ComponentID MIN_COMPONENT_ID          = 0;
const ComponentID MAX_COMPONENT_ID          = 32; // maximum components per entity

using ComponentSet = std::bitset<MAX_COMPONENT_ID>; // 00000000000000000000000000000000

#endif // ALIAS_H
