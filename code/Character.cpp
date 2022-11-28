#include "Character.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int Character::getHealth()
{
    return health;
}

Vector2f Character::getPosition()
{
    return position;
}

Sprite Character::getSprite()
{
    return characterSprite;
}