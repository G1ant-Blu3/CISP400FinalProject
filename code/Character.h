#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Character
{
    public:
        void virtual movement(float elapsedTime, RenderWindow& window) = 0;
        int getHealth();
        Vector2f getPosition();
        Sprite getSprite();
    protected:
        Texture characterTexture;
        Sprite characterSprite;
        int health = 100;
        float speed = 1000.0;
        Vector2f position;
};