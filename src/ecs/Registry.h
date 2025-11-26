#pragma once
#include "Entity.h"
#include "Movement.h"
#include "Position.h"
#include <unordered_map>
#include <vector>
#include <any>

// manages which ID's are being used for entities, creates/destroyes entities
class Registry
{
public:
    Registry();
    
    Entity createEntity(EntityType type = EntityType::INVALID);
    void destoryEntity(Entity entity);
    
    template<typename T>
    void addComponent(Entity entity, T component);
    
    template<typename T>
    T& getComponent(Entity entity);

    template<typename T>
    bool hasComponent(Entity entity);

    template<typename T>
    auto& getComponentPool();

private:
    uint32_t mnNextID = 1;
    std::unordered_map<uint32_t, Entity> mhEntities;
    std::unordered_map<std::type_info, std::any> mhComponentPool;
};