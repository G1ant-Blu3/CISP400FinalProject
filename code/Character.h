#pragma once
#include "drawmap.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Character
{
    public:
        
        void jump(float elapsedTime, RenderWindow& window,drawmap& map);
        Vector2f getPosition();
        Sprite getSprite();
        float getSpeed();
        float getGravity();
        void jumpcalc(float elapsedTime, RenderWindow& window,drawmap& map);
        void virtual movement(float elapsedTime, RenderWindow& window,drawmap& map) = 0;
        
        void moveleft(float elapsedTime, RenderWindow& window,drawmap& map);
        void moveright(float elapsedTime, RenderWindow& window,drawmap& map);
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
        float gravity = 600.0;
};  