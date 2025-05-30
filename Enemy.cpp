#include "raylib.h"
#include "raymath.h"
#include "Enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f; // Set a default speed for the enemy
}

void Enemy::tick(float deltaTime)
{
    // Get toTarget
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);
    // Normalize toTarget
    toTarget = Vector2Normalize(toTarget);
    // muliply toTarget by speed
    toTarget = Vector2Scale(toTarget, speed);
    // Move the enemy towards the target
    worldPos = Vector2Add(worldPos, toTarget);
    
    if (target)
    {
        screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    }
    BaseCharacter::tick(deltaTime);
}