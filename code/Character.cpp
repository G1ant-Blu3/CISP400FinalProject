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
void Character::moveright(float elapsedTime, RenderWindow& window, drawmap& map, Character& otherPlayer) {
    float offset = getSpeed() * elapsedTime;
    bool colision = false;
    right = true;
    left = false;
    if (position.x <= window.getSize().x - characterSprite.getGlobalBounds().width)
    {
        //characterSprite.setScale(5.0, 5.0); displaces the image then where it actually is
        
        FloatRect rectangle(Vector2f(position.x + offset, position.y), Vector2f(characterSprite.getGlobalBounds().width, characterSprite.getGlobalBounds().height));
        if(rectangle.intersects(otherPlayer.getSprite().getGlobalBounds()))
        {
            colision = true;
            
        }
        for (int i = 0; i < map.wallBounds.size(); i++)
        {
            FloatRect rectangle(Vector2f(position.x + offset, position.y), Vector2f(characterSprite.getGlobalBounds().width, characterSprite.getGlobalBounds().height));
            if (rectangle.intersects(map.wallBounds[i]))
            {
              colision = true;
            }
        }
    }
        if (colision == false)
        {
            position.x += offset;
            characterSprite.setPosition(position);
        }
   
}

void Character::moveleft(float elapsedTime, RenderWindow& window, drawmap& map, Character& otherPlayer) {
    left = true;
    right = false;
    float offset = getSpeed() * elapsedTime;
    bool colision = false;
    if (position.x >= characterSprite.getGlobalBounds().width)
    {
        // characterSprite.setScale(-5.0, 5.0); This function messes with collision, find a different way to rotate the rectangle without messing up the cords
        
        FloatRect rectangle(Vector2f(position.x - 1, position.y), Vector2f(characterSprite.getGlobalBounds().width, characterSprite.getGlobalBounds().height));
        if(rectangle.intersects(otherPlayer.characterSprite.getGlobalBounds())) // there is no need to add -offset to x if your just checking the closest position of x so -1 if the closest
            // dont need to recreate to global bounds of the character
        {
            colision = true;
        }
        for (int i = 0; i < map.wallBounds.size(); i++)
        {
            
            if(rectangle.intersects(map.wallBounds[i]))
            {
                colision = true;
                
            }
        }
    }
    if(colision == false) 
    {
        position.x -= offset;
        characterSprite.setPosition(position);
    }
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
void Character::jumpcalc(float elapsedTime, RenderWindow& window, drawmap& map, Character& otherPlayer) {
    // find a way to constanly apply gravity
    if (!isJumping && !isFalling) 
    {
        isFalling = true;
        FloatRect rectangle(Vector2f(position.x, position.y - 1), Vector2f(characterSprite.getGlobalBounds().width, characterSprite.getGlobalBounds().height));
        if (rectangle.intersects(otherPlayer.characterSprite.getGlobalBounds())) {
            isFalling = false;
        }
       
        for (int i = 0; i < map.wallBounds.size(); i++)
        {
             if (rectangle.intersects(map.wallBounds[i]))
             {
                    isFalling = false;
             }

        }
        if (position.y >= window.getSize().y - characterSprite.getGlobalBounds().height)
        {
            position.y = window.getSize().y - characterSprite.getGlobalBounds().height;
            characterSprite.setPosition(position);
            isFalling = false;
        }

        

    }
    if (isJumping)
    {
        timeOfCurrentJump += elapsedTime;
        
        FloatRect rectangle(Vector2f(position.x, position.y), Vector2f(characterSprite.getGlobalBounds().width, characterSprite.getGlobalBounds().height + 1));
        if (rectangle.intersects(otherPlayer.characterSprite.getGlobalBounds()))
        {
            isJumping = false;
        }
        for (int i = 0; i < map.wallBounds.size(); i++)
        {
            if (rectangle.intersects(map.wallBounds[i]))
            {
                isJumping = false;
            }
        }

        if (timeOfCurrentJump < jumpDuration)
        {
            float offset = getGravity() * 1.5 * elapsedTime;
           
            if (isJumping == true)
            {
                position.y -= offset;
                characterSprite.setPosition(position);
            }
            else
            {
                isJumping = false;
                isFalling = true;
            }
            
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
            float offset = getGravity() * elapsedTime;           
            FloatRect rectangle(Vector2f(position.x, position.y + 10), Vector2f(characterSprite.getGlobalBounds().width, characterSprite.getGlobalBounds().height));
            if (rectangle.intersects(otherPlayer.getSprite().getGlobalBounds()))
            {
                isFalling = false;
            }
               
                for(int i = 0; i < map.wallBounds.size(); i++)
                {
                    if (rectangle.intersects(map.wallBounds[i])) 
                    {
                        isFalling = false;
                    }

                }
            
            if(isFalling == true)
            {
                position.y += offset;
                characterSprite.setPosition(position);
            }
            
            if(position.y >= window.getSize().y - characterSprite.getGlobalBounds().height)
            {
                position.y = window.getSize().y - characterSprite.getGlobalBounds().height;
                characterSprite.setPosition(position);
                isFalling = false;
            }
        }
    }
}
void Character::ifhit()
{

        ishit = false;
        health = health - 50;
        if (health <= 0)
        {
            isdead = true;
            health = 100;
        }

}