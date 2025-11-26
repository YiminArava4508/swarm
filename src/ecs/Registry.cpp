#include "Registry.h"
#include "Entity.h"

Entity Registry::createEntity(EntityType type)
{
    Entity entity{mnNextID++, type};
    mhEntities.insert({mnNextID, entity});

    return entity;
}

void Registry::destoryEntity(Entity entity)
{
    // simply delete from entity map
    mhEntities.erase(entity.id);
}

template<typename T>
void Registry::addComponent(Entity entity, T component)
{
    // extract the corresponding component type
    auto& poolAny = mhComponentPool[typeid(T)];

    // if this pool does not exist yet, create it
    if (!poolAny.has_value())
    {
        poolAny = std::unordered_map<Entity, T>{};
    }

    // pool behaves as an unordered_map<Entity, T> alias
    auto& pool = std::any_cast<std::unordered_map<Entity, T>&>(poolAny);

    pool[entity] = component;
}

template<typename T>
T& Registry::getComponent(Entity entity)
{
    // extract corresponding component type from our component pool
    auto& poolAny = mhComponentPool[typeid(T)];
    auto& pool = std::any_cast<std::unordered_map<Entity, T>&>(poolAny);

    return pool[entity];
}

template<typename T>
bool Registry::hasComponent(Entity entity)
{
    auto& poolAny = mhComponentPool[typeid(T)];
    if (!poolAny.has_value())
        return false;

    auto& pool = std::any_cast<std::unordered_map<Entity, T>&>(poolAny);
    
    return pool.contains(entity)
}

template<typename T>
auto& Registry::getComponentPool()
{
    auto& anyComponentPool = mhComponentPool[typeid(T)];
    if (!anyComponentPool.has_value())
        return false;

    auto& specificComponentPool = std::any_cast<std::unordered_map<Entity, T>>(anyComponentPool);

    return specificComponentPool;
}