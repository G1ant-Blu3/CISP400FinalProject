#include "PlayerOne.h"
using namespace sf;


PlayerOne::PlayerOne()
{
    jumpDuration = 0.5;
    characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle1.png");
    //IntRect rectangle(4, 14, 19, 34); // dont need to use this dumb funciton
    characterSprite.setTexture(characterTexture);
    //characterSprite.setTextureRect(rectangle);
    characterSprite.setScale(3.0, 3.0);
}

void PlayerOne::spawn(RenderWindow& window)
{
    position = Vector2f(0.0, window.getSize().y - characterSprite.getGlobalBounds().height);
    characterSprite.setPosition(position);
}

void PlayerOne::movement(float elapsedTime, RenderWindow& window, drawmap& map, Character& otherPlayer)
{
    if (ishit == true) 
    {
        ifhit();
    }
    if (isdead == true)
    {
        otherPlayer.otherdead = true;
        health = 100;
        spawn(window);
        isdead = false;
    }
    if (otherdead == true)
    {
        otherdead = false;
        health = 100;
        spawn(window);
    }
    jumpcalc(elapsedTime,window, map, otherPlayer); //has to be included in a loop in the game for physics to be calculated
    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        jump(elapsedTime,window,map);
    }

    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        moveleft(elapsedTime, window, map, otherPlayer);
        ismoving = true;
    }

    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        
        moveright(elapsedTime, window, map, otherPlayer);
        ismoving = true;
    }
    if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A))
    {
        ismoving = false;
    }
}
