#include "PlayerOne.h"
using namespace sf;
#include "tile.h"

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

void PlayerOne::movement(float elapsedTime, RenderWindow& window, drawmap& map)
{
    jumpcalc(elapsedTime,window, map); //has to be included in a loop in the game for physics to be calculated
    if(Keyboard::isKeyPressed(Keyboard::W))
    {
       
        jump(elapsedTime,window,map);
    }
    
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        moveleft(elapsedTime, window, map);
    }

    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        
        moveright(elapsedTime, window, map);
    }
}
