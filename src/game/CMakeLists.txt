# Create the Game static library
add_library(Game STATIC
    Game.cpp

    ## ECS core
    ../ecs/Registry.cpp

    # ECS systems
    ../ecs/systems/MovementSystem.cpp
    ../ecs/systems/RenderSystem.cpp
)

# Add ECS include dirs
target_include_directories(Game PUBLIC
    ${PROJECT_SOURCE_DIR}/src/ecs
    ${PROJECT_SOURCE_DIR}/src/ecs/components
    ${PROJECT_SOURCE_DIR}/src/ecs/systems
)

# Make headers visible to anything using Game
target_include_directories(Game PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

# Link dependencies used within Game
target_link_libraries(Game
    PUBLIC
        raylib
)
