cmake_minimum_required(VERSION 3.16)

project(SwarmOpenGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/Dependencies.cmake)

add_executable(swarm_app
    src/main.cpp
)

target_include_directories(swarm_app PRIVATE include)

find_package(OpenGL REQUIRED)
target_link_libraries(swarm_app PRIVATE glfw OpenGL::GL)

if(APPLE)
    target_link_libraries(swarm_app PRIVATE "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()

add_custom_command(
    TARGET swarm_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
            $<TARGET_FILE_DIR:swarm_app>/shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/shaders
            $<TARGET_FILE_DIR:swarm_app>/shaders
    COMMENT "Copying shader assets to output directory"
)

install(TARGETS swarm_app RUNTIME DESTINATION bin)
