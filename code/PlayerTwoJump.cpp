#include "PlayerTwo.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void PlayerTwo::jump(float elapsedTime, RenderWindow& window)
{
    if(isJumping)
    {
        timeOfCurrentJump += elapsedTime;

        if(timeOfCurrentJump < jumpDuration)
        {
            position.y -= getGravity() * 2.0 * elapsedTime;
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