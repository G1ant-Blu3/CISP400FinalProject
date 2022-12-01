#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Character
{
    public:
        
        void jump(float elapsedTime, RenderWindow& window);
        Vector2f getPosition();
        Sprite getSprite();
        float getSpeed();
        float getGravity();
        void jumpcalc(float elapsedTime, RenderWindow& window);
        void virtual movement(float elapsedTime, RenderWindow& window) = 0;
        
        void moveleft(float elapsedTime, RenderWindow& window);
        void moveright(float elapsedTime, RenderWindow& window);
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