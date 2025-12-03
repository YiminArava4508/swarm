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
    entityRender.imagePath = "../assets/scarfy.png";

    Texture2D scarfySprite = LoadTexture(entityRender.imagePath.c_str());
    Vector2 renderPosition = { (float)entityPos.x, (float)entityPos.y};
    Rectangle frameRec = {0.0f, 0.0f, (float)scarfySprite.width/6, (float)scarfySprite.height };

    uint16_t currentFrame = 0;
    uint16_t framesCounter = 0;
    uint16_t framesSpeed = 8;

    while(!WindowShouldClose())
    {
        framesCounter++;
        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;
            if (currentFrame > 5)
            {
                currentFrame = 0;
            }
            frameRec.x = (float)currentFrame*(float)scarfySprite.width/6;
        }
        /*
        example systems code
            renderSystem();
            movementSystem();
            inputSystem();
        */
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(scarfySprite, 15, 40, WHITE);
        DrawRectangleLines(15, 40, scarfySprite.width, scarfySprite.height, LIME);
        DrawRectangleLines(15 + (int)frameRec.x, 40 + (int)frameRec.y, (int)frameRec.width, (int)frameRec.height, RED);

        DrawTextureRec(scarfySprite, frameRec, renderPosition, WHITE);

        EndDrawing();
    }

    UnloadTexture(scarfySprite);
    CloseWindow();
    
    mbIsRunning = false;
}

// void Game::Render()
// {
//     // // render circle that goes to clicked position
//     // Vector2 myCircle = (Vector2){0, (float)WINDOW_HEIGHT / 2.0f};
// }

bool Game::IsRunning() const
{
    return mbIsRunning;
}
