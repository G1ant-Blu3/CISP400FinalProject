#include "PlayerTwo.h"
#include <SFML/Graphics.hpp>
using namespace sf;

PlayerTwo::PlayerTwo()
{
    characterTexture.loadFromFile("graphics/thomas.png");
    characterSprite.setTexture(characterTexture);
    characterSprite.setScale(2.5, 2.5);
    characterSprite.setColor(Color::Green);
}

void PlayerTwo::spawn(RenderWindow& window)
{
    position = Vector2f(window.getSize().x - characterSprite.getGlobalBounds().width, window.getSize().y - characterSprite.getGlobalBounds().height);
    characterSprite.setPosition(position);
}

void PlayerTwo::movement(float elapsedTime, RenderWindow& window)
{
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        if(position.x >= 0.0)
        {
            position.x -= speed * elapsedTime;
        }
        characterSprite.setPosition(position);
    }

    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        if(position.x <= window.getSize().x - characterSprite.getGlobalBounds().width)
        {
            position.x += speed * elapsedTime;
        }
        characterSprite.setPosition(position);
    }
}