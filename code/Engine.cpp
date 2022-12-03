#include "engine.h"
#include "PlayerOne.h"
#include "PlayerTwo.h"
#include <SFML/Graphics.hpp>
#include "drawmap.h"
#include "projectilemap.h"

using namespace sf;

engine::engine() {


}
void engine::run() {
    {
        Vector2f resolution;
        resolution.x = VideoMode::getDesktopMode().width;
        resolution.y = VideoMode::getDesktopMode().height;


        RenderWindow window(VideoMode(resolution.x, resolution.y), "Final Project", Style::Default);
        Texture background;
        background.loadFromFile("graphics/background.png");
        Sprite s_background;
        s_background.setTexture(background);
        drawmap map;
        projectilemap projmap;

        PlayerOne playerOne;
        PlayerTwo playerTwo;
        playerOne.spawn(window);
        playerTwo.spawn(window);

        

        Clock clock;

        while (window.isOpen())
        {
            Time dt = clock.restart();
            float dtAsSeconds = dt.asSeconds();

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
            }
            
            map.checkmouse(window);
            playerOne.movement(dtAsSeconds, window, map, playerTwo);
            playerTwo.movement(dtAsSeconds, window, map, playerOne);

            window.clear();
            window.draw(s_background);
            
            for (int i = 0; i < map.tilevector.size(); i++) {
                
                window.draw(map.tilevector.at(i)->returnsprite());
            }
            
            window.draw(playerOne.getSprite());
            window.draw(playerTwo.getSprite());
            window.display();
        }

       
    }

}