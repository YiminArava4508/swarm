#include "Registry.h"
#include "components/Components.h"
#include "raylib.h"

inline void RenderSystem(Registry& registry)
{
    // pull the components
    auto& positions = registry.getComponentPool<Position>();
    auto& renders = registry.getComponentPool<Render>();

    for (const std::pair<Entity, Render>& e : renders)
    {
        Image image = LoadImage(renders[e.first].imagePath);

        Texture2D texture = LoadTextureFromImage(image);
        UnloadImage(image);
        image = LoadImageFromTexture(texture);
        UnloadTexture(texture);
        texture = LoadTextureFromImage(image);
        UnloadImage(image);

        DrawTexture(texture, positions[e.first].x, positions[e.first].y, WHITE);
    }
}