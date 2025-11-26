#pragma once
#include <cstdint>
#include <string>

enum class EntityType
{
    INVALID = 0,
    EXAMPLE,
};

struct Entity
{
    // unitialized state
    std::uint32_t id = 0;
    EntityType type = EntityType::INVALID;

    // use default values
    Entity() = default;

    //  parameterized constructor
    Entity(std::uint32_t _id, EntityType _type) : id(_id), type(_type) {}

    // for use to determine if entity should be rendered
    bool isValid() const noexcept { return id != 0 && type != EntityType::INVALID; }
};