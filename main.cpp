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

    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    Texture2D knight = knight_idle; // Default to idle

    Vector2 knightPosition = {
        (float)windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
        (float)windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
    };
// 1 : facing right, -1 : facing left
float rightLeft{1.f}; // Direction for character facing

// anim variables 
float runningTime{};
int frame{};
const int maxFrames{6}; // Total frames in the knight sprite sheet
const float updateTime{1.0f/12.0f}; // Time per frame for animation
    
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

        // Set knight texture based on movement
        if (Vector2Length(direction) == 0.0f)
        {
            knight = knight_idle;
        }
        else
        {
            knight = knight_run;
            direction = Vector2Normalize(direction);
            direction = Vector2Scale(direction, speed); // Scale movement by speed
            mapPosition = Vector2Subtract(mapPosition, direction);
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f; // Update facing direction
        }

        // draw the map
        DrawTextureEx(map, mapPosition, rotation, scale, tint);

        // update animation frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            runningTime = 0.0f;
            frame++;
            if (frame > maxFrames) frame = 0; // Loop back to the first frame
        };

        // draw the character
        Rectangle source{frame * (float)knight.width/6.f, 0.f, rightLeft * (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPosition.x, knightPosition.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);


        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();

    return 0;
}