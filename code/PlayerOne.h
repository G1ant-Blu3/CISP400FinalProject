#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class PlayerOne : public Character
{
    public:
        PlayerOne();
        void spawn(RenderWindow& window);
        void virtual movement(float elapsedTime, RenderWindow& window);
};