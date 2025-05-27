#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;

    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    Vector2 mapPosition = { 0.0f, 0.0f };
    float scale = 4.0f;
    float rotation = 0.0f;
    Color tint = WHITE;
    float speed = 4.0f; // Movement speed
    // Removed unused variable 'knightScale'
    // Removed unused variable 'knightOrigin'

Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
Vector2 knightPosition = {
    (float)windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
    (float)windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
};

SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0f;
        if (IsKeyDown(KEY_D)) direction.x += 1.0f;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0f;
        if (IsKeyDown(KEY_S)) direction.y += 1.0f;
        if (Vector2Length(direction) != 0.0f)
        {
            direction = Vector2Normalize(direction);
            direction = Vector2Scale(direction, speed); // Scale movement by speed
            mapPosition = Vector2Subtract(mapPosition, direction);
        }

        // draw the map
        DrawTextureEx(map, mapPosition, rotation, scale, tint);

        // draw the character
        Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPosition.x, knightPosition.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);


        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();

    return 0;
}