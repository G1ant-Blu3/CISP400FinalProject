#include "PlayerTwo.h"
#include "drawmap.h"
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

void PlayerTwo::movement(float elapsedTime, RenderWindow& window, drawmap& map, Character& otherPlayer)
{
    jumpcalc(elapsedTime, window, map);
    if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        jump(elapsedTime, window, map);

    }
    
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        moveleft(elapsedTime, window, map, otherPlayer);
    }

    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        moveright(elapsedTime, window, map, otherPlayer);
    }

}