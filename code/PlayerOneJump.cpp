#include "PlayerOne.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void PlayerOne::jump(float elapsedTime, RenderWindow& window)
{
    if(isJumping)
    {
        timeOfCurrentJump += elapsedTime;

        if(timeOfCurrentJump < jumpDuration)
        {
            position.y -= getGravity() * 1.5 * elapsedTime;
        }
        else
        {
            isJumping = false;
            isFalling = true;
        }
    }

    if(isFalling)
    {
        if(position.y < window.getSize().y - characterSprite.getGlobalBounds().height)
        {
            position.y += getGravity() * elapsedTime;
            if(position.y >= window.getSize().y - characterSprite.getGlobalBounds().height)
            {
                position.y = window.getSize().y - characterSprite.getGlobalBounds().height;
                isFalling = false;
            }
        }
    }

    characterSprite.setPosition(position);
}