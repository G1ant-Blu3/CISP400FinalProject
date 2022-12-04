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
        void jumpcalc(float elapsedTime, RenderWindow& window,drawmap& map, Character& otherPlayer);
        void virtual movement(float elapsedTime, RenderWindow& window,drawmap& map, Character& otherPlayer) = 0;
        void ifhit();
        void moveleft(float elapsedTime, RenderWindow& window,drawmap& map, Character& otherPlayer);
        void moveright(float elapsedTime, RenderWindow& window,drawmap& map, Character& otherPlayer);
        bool left = false;
        bool right = true;
        bool ishit = false;
        float firedtime;
        float health = 100;
        bool isdead = false;
        float timesdead = 0;
        bool isJumping = false;
        bool isFalling = false;
        bool isfiring = false;
        bool ismoving = false;
        bool beenhit = false;
        Texture characterTexture;
        Sprite characterSprite;
        bool justjumped = false;
        bool justfired = false;
    protected:
        
        
        Vector2f position;
        float jumpDuration;
        float timeOfCurrentJump;
     
        
        
    private:
        float speed = 1000.0;
        float gravity = 600.0;
};  