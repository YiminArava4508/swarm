#pragma once
#include "ecs/Entity.h"
#include "ecs/components/Components.h"
#include <unordered_map>
#include <typeindex>
#include <vector>
#include <any>

// manages which ID's are being used for entities, creates/destroyes entities
class Registry
{
public:
    Registry();
    ~Registry();

    void createEntity(EntityType type = EntityType::INVALID);
    void destoryEntity(Entity entity);
    bool isValidEntity(uint32_t index);

    template<typename T>
    void addComponent(uint32_t entity, T component);
    
    template<typename T>
    T& getComponent(Entity entity);

    template<typename T>
    bool hasComponent(Entity entity);

    template<typename T>
    auto& getComponentPool();

private:
    uint32_t mnNextID = 1;
    std::unordered_map<uint32_t, Entity> mhEntities;
    std::unordered_map<std::type_index, std::any> mhComponentPool;
};