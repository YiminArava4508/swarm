#pragma once
#include "Registry.h"
#include "components/Movement.h"
#include "components/Position.h"

inline void MovementSystem(Registry& registry, float dt)
{
    // gather all entities with Transform component
    auto& positions = registry.getComponentPool<Position>();

    // gather all entities with Velocity component
    auto& velocities = registry.getComponentPool<Movement>();

    // all entities will velocity should have position implemented
    for (const std::pair<Entity, Movement>& e : velocities)
    {
        positions[e.first].x += e.second.v_x;
        positions[e.first].y += e.second.v_y;
    }
}