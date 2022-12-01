#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h" // ensure header files are here before SFML is define



using namespace sf;

float Character::getSpeed()
{
    return speed;
}

float Character::getGravity()
{
    return gravity;
}

Vector2f Character::getPosition()
{
    return position;
}

Sprite Character::getSprite()
{
    return characterSprite;
}
void Character::moveright(float elapsedTime, RenderWindow& window, drawmap& map) {

    if (position.x <= window.getSize().x - characterSprite.getGlobalBounds().width)
    {
        characterSprite.setScale(5.0, 5.0);
        position.x += getSpeed() * elapsedTime;
    }

    characterSprite.setPosition(position);
}
void Character::moveleft(float elapsedTime, RenderWindow& window, drawmap& bound) {
    
    if (position.x >= characterSprite.getGlobalBounds().width)
    {
        characterSprite.setScale(-5.0, 5.0);
        position.x -= getSpeed() * elapsedTime;
    }
    characterSprite.setPosition(position);

}
void Character::jump(float elapsedTime, RenderWindow& window, drawmap& map) //needs jumpcalc(elapsedTime,window); for it to work
{
    if (!isJumping && !isFalling)
    {
        isJumping = true;
        timeOfCurrentJump = 0.0;
    }
 
}
// has to be in a movement loop for it to calcuate during the game
void Character::jumpcalc(float elapsedTime, RenderWindow& window, drawmap& map) {
    if (isJumping)
    {
        timeOfCurrentJump += elapsedTime;

        if (timeOfCurrentJump < jumpDuration)
        {
            position.y -= getGravity() * 1.5 * elapsedTime;
        }
        else
        {
            isJumping = false;
            isFalling = true;
        }
    }

    if (isFalling)
    {
        if (position.y < window.getSize().y - characterSprite.getGlobalBounds().height)
        {
            position.y += getGravity() * elapsedTime;
            if (position.y >= window.getSize().y - characterSprite.getGlobalBounds().height)
            {
                position.y = window.getSize().y - characterSprite.getGlobalBounds().height;
                isFalling = false;
            }
        }
    }

    characterSprite.setPosition(position);
}