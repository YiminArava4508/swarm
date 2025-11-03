cmake_minimum_required(VERSION 3.15)
project(swarm LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binaries into build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add executable
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    OpenGL::GL
    glfw
)

# Optional: copy shader resources to build directory
file(COPY ${PROJECT_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR}/bin)
