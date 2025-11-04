# Create the Game static library
add_library(Game STATIC
    Game.cpp
)

# Make headers visible to anything using Game
target_include_directories(Game PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

# Link dependencies used within Game
target_link_libraries(Game
    PUBLIC
        OpenGL::GL
        glfw
)
