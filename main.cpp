#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "Prop.h"

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPosition = {0.0f, 0.0f};

    const float mapScale{4.0f};

    // create an instance of the character class and set its screen position
    Character knight(windowWidth, windowHeight);

    Prop props[2] = {
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")},
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        mapPosition = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPosition, 0.f, mapScale, WHITE);

        // draw the props
        for (auto prop : props)
        {
            // render each prop relative to the knight's position
            prop.Render(knight.getWorldPos());
        }

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

        // check for collisions with props
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec()))
            {
                knight.undoMovement(); // undo the last movement if colliding with a prop
            }
        }

        EndDrawing();
    
    }

    UnloadTexture(map);
    CloseWindow();

    return 0;
}