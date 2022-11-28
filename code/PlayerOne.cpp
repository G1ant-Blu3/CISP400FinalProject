#include "PlayerOne.h"
#include <SFML/Graphics.hpp>
using namespace sf;

PlayerOne::PlayerOne()
{
    characterTexture.loadFromFile("graphics/thomas.png");
    characterSprite.setTexture(characterTexture);
    characterSprite.setScale(2.5, 2.5);
    characterSprite.setColor(Color::Blue);
}

void PlayerOne::spawn(RenderWindow& window)
{
    position = Vector2f(0.0, window.getSize().y - characterSprite.getGlobalBounds().height);
    characterSprite.setPosition(position);
}

void PlayerOne::movement(float elapsedTime, RenderWindow& window)
{
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        if(position.x >= 0.0)
        {
            position.x -= speed * elapsedTime;
        }
        characterSprite.setPosition(position);
    }

    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        if(position.x <= window.getSize().x - characterSprite.getGlobalBounds().width)
        {
            position.x += speed * elapsedTime;
        }
        characterSprite.setPosition(position);
    }
}