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
}

void Enemy::tick(float deltaTime)
{
    if (target)
    {
        screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    }
    BaseCharacter::tick(deltaTime);
}