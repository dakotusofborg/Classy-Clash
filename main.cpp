#include "raylib.h"
#include "raymath.h"

// Character class definition
class Character
{
public:
    Vector2 getWorldPos() const { return worldPos; }
    void setScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.f}; // Direction for character facing

    // anim variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};               // Total frames in the knight sprite sheet
    const float updateTime{1.0f / 12.0f}; // Time per frame for animation
    const float speed{4.0f};              // Movement speed
};

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
}

void Character::tick(float deltaTime)
{
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0f;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0f;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0f;

    // Set knight texture based on movement
    if (Vector2Length(direction) != 0.0f)
    {
        // set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f; // Update facing direction
        texture = run;                                          // Use running texture
    }
    else
    {
        texture = idle; // Use idle texture
    }

    // Update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0.0f;
        frame++;
        if (frame > maxFrames)
            frame = 0; // lop back to first frame
    }

    // draw the character
    Rectangle source{frame * (float)texture.width / 6.f, 0.f, rightLeft * (float)texture.width / 6.f, (float)texture.height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width / 6.0f, 4.0f * (float)texture.height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    Vector2 mapPosition = {0.0f, 0.0f};
    float scale = 4.0f;
    float rotation = 0.0f;
    Color tint = WHITE;

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
        DrawTextureEx(map, mapPosition, rotation, scale, tint);

        // update and draw the character
        knight.tick(GetFrameTime());

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();

    return 0;
}