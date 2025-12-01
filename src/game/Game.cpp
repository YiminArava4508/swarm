#include "ecs/Registry.h"
#include "raylib.h"
#include "Game.h"
#include <iostream>
#include <exception>

namespace
{
    constexpr int WINDOW_WIDTH{800};
    constexpr int WINDOW_HEIGHT{450};
}

Game::Game() : msTitle("Swarm"), mbIsRunning(true) {}

Game::~Game() {};

void Game::Run()
{
    // init window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, msTitle.c_str());
    SetTargetFPS(60);

    Registry registry{};
    registry.createEntity(EntityType::EXAMPLE);
    std::cout << std::boolalpha << "Entity valid: " << registry.isValidEntity(1) << std::endl;

    std::cout << "Add position and render components to newly created entity" << std::endl;
    Position entityPos;
    entityPos.x = WINDOW_WIDTH / 2;
    entityPos.y = WINDOW_HEIGHT / 2;

    Render entityRender;
    entityRende while (!WindowShouldClose())
    {
        /*
        example systems code
            renderSystem();
            movementSystem();
            inputSystem();
        */
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    mbIsRunning = false;
}

void Game::Render()
{
    // // render circle that goes to clicked position
    // Vector2 myCircle = (Vector2){0, (float)WINDOW_HEIGHT / 2.0f};
}

bool Game::IsRunning() const
{
    return mbIsRunning;
}
