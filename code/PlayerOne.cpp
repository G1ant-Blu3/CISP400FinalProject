#include "PlayerOne.h"
using namespace sf;
#include "tile.h"
#include "drawmap.h"

PlayerOne::PlayerOne()
{
    jumpDuration = 0.5;
    characterTexture.loadFromFile("graphics/biker_idle.png");
    IntRect rectangle(4, 14, 19, 34);
    characterSprite.setTexture(characterTexture);
    characterSprite.setTextureRect(rectangle);
    characterSprite.setScale(5.0, 5.0);
}

void PlayerOne::spawn(RenderWindow& window)
{
    position = Vector2f(0.0, window.getSize().y - characterSprite.getGlobalBounds().height);
    characterSprite.setPosition(position);
}

void PlayerOne::movement(float elapsedTime, RenderWindow& window)
{
    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        if(!isJumping && !isFalling)
        {
            isJumping = true;
            timeOfCurrentJump = 0.0;
        }
    }
    jump(elapsedTime, window);
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        if(position.x >= characterSprite.getGlobalBounds().width)
        {
            characterSprite.setScale(-5.0 , 5.0);
            position.x -= getSpeed() * elapsedTime;
        }
        characterSprite.setPosition(position);
    }

    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        if(position.x <= window.getSize().x - characterSprite.getGlobalBounds().width)
        {
            characterSprite.setScale(5.0, 5.0);
            position.x += getSpeed() * elapsedTime;
        }
        characterSprite.setPosition(position);
    }
}
