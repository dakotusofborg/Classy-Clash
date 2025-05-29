#include "raylib.h"
#include "BaseCharacter.h"
#pragma once

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    void tick(float deltaTime) override;

private:
   
};
