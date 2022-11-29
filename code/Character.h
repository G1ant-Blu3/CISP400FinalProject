#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Character
{
    public:
        void virtual movement(float elapsedTime, RenderWindow& window) = 0;
        void virtual jump(float elapsedTime, RenderWindow& window) = 0;
        Vector2f getPosition();
        Sprite getSprite();
        float getSpeed();
        float getGravity();
    protected:
        Texture characterTexture;
        Sprite characterSprite;
        Vector2f position;
        float jumpDuration;
        float timeOfCurrentJump;
        bool isJumping = false;
        bool isFalling = false;
    private:
        float speed = 1000.0;
        float gravity = 300.0;
};