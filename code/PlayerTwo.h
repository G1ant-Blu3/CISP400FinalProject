#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>





using namespace sf;

class PlayerTwo : public Character
{
    public:
        PlayerTwo();
        void spawn(RenderWindow& window);
        void virtual movement(float elapsedTime, RenderWindow& window, drawmap& map);
        
};