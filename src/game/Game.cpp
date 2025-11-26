 #include <iostream>
 #include "Entity.h"
 #include "Game.h"
 #include "Registry.h"
 #include "raylib.h"

 namespace
 {
    constexpr int WINDOW_WIDTH {800};
    constexpr int WINDOW_HEIGHT {450};
 }

Game::Game() : msTitle("Swarm"), mbIsRunning(true) {}

Game::~Game() {};

void Game::Run()
{
    // init window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, msTitle.c_str());
    SetTargetFPS(60);

    Registry registry;
    registry.createEntity(EntityType::EXAMPLE);
    
    
    while (!WindowShouldClose()) 
    {
        // draw entities
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
