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
    if (!getAlive()) return;

    // Get velocity
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    BaseCharacter::tick(deltaTime);
}

Vector2 Enemy::getScreenPos()
{
        return Vector2Subtract(worldPos, target->getWorldPos());
}
