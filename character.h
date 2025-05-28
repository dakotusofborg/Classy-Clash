#include "raylib.h"

class Character
{
public:
    Character(); // constructor to initialize the character
    Vector2 getWorldPos() const { return worldPos; }
    void setScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    float width{};
    float height{};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.f}; // Direction for character facing

    // anim variables
    float runningTime{};
    int frame{};
    int maxFrames{6};               // Total frames in the knight sprite sheet
    float updateTime{1.0f / 12.0f}; // Time per frame for animation
    float speed{4.0f};              // Movement speed
};