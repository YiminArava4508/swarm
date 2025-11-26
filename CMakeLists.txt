cmake_minimum_required(VERSION 3.15)
project(swarm LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binaries into build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find required packages
# find_package(OpenGL REQUIRED)
# find_package(glfw3 3.3 REQUIRED)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectory for the Game module
add_subdirectory(src/game)
add_subdirectory(external/raylib)

# Add main executable
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Link the Game library to the executable
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        raylib
        Game
)

# Optional: copy resource files to build/bin
file(COPY ${PROJECT_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR}/bin)
