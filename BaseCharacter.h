#include "Raylib.h"

#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    virtual void tick(float deltaTime);
    void undoMovement(); // for future use, e.g., when the character goes out of bounds
    Rectangle getCollisionRec();
    virtual Vector2 getScreenPos() = 0; // pure virtual function to get screen position
protected: 
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.f};
    // animation variables
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{4.f};
    Vector2 velocity{};
private:
};

#endif // BASE_CHARACTER_H