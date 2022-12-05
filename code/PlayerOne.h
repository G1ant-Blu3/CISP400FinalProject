#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h" 
#include "drawmap.h"


using namespace sf;

class PlayerOne : public Character
{
    public:
        PlayerOne();
        void spawn(RenderWindow& window);
        void virtual movement(float elapsedTime, RenderWindow& window, drawmap& map, Character& otherPlayer);
        
};