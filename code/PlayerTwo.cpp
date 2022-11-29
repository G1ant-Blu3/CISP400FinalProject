#include "PlayerTwo.h"
using namespace sf;

PlayerTwo::PlayerTwo()
{
    jumpDuration = 0.5;
    characterTexture.loadFromFile("graphics/Punk_idle.png");
    IntRect rectangle(5, 14, 17, 34);
    characterSprite.setTexture(characterTexture);
    characterSprite.setTextureRect(rectangle);
    characterSprite.setScale(-5.0, 5.0);
}

void PlayerTwo::spawn(RenderWindow& window)
{
    position = Vector2f(window.getSize().x, window.getSize().y - characterSprite.getGlobalBounds().height);
    characterSprite.setPosition(position);
}

void PlayerTwo::movement(float elapsedTime, RenderWindow& window)
{
    if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        if(!isJumping && !isFalling)
        {
            isJumping = true;
            timeOfCurrentJump = 0.0;
        }
    }
    jump(elapsedTime, window);
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        if(position.x >= characterSprite.getGlobalBounds().width)
        {
            characterSprite.setScale(-5.0, 5.0);
            position.x -= getSpeed() * elapsedTime;
        }
        characterSprite.setPosition(position);
    }

    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        if(position.x <= window.getSize().x - characterSprite.getGlobalBounds().width)
        {
            characterSprite.setScale(5.0, 5.0);
            position.x += getSpeed() * elapsedTime;
        }
        characterSprite.setPosition(position);
    }
}