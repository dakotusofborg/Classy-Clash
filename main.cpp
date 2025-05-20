#include "raylib.h"

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

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(map, mapPosition, rotation, scale, tint);

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();

    return 0;
}