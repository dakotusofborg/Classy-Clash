#include "raylib.h"
#include "raymath.h"
#include "character.h"

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPosition = {0.0f, 0.0f};

    const float mapScale{4.0f};

    // create an instance of the character class and set its screen position
    Character knight;
    knight.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        mapPosition = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPosition, 0.f, mapScale, WHITE);

        // update and draw the character
        knight.tick(GetFrameTime());
        // check if the character is within the bounds of the map
        if (knight.getWorldPos().x < 0.f || 
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + windowWidth > map.width * mapScale ||
            knight.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            knight.undoMovement(); // undo the last movement if out of bounds
        }

        EndDrawing();
    
    }

    UnloadTexture(map);
    CloseWindow();

    return 0;
}