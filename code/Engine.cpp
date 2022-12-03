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

        Clock proj;

        Clock clock;

        while (window.isOpen())
        {
            Time jf = proj.getElapsedTime();
            Time dt = clock.restart();
            float dtAsSeconds = dt.asSeconds();
            float jfMilliseconds = jf.asMilliseconds();

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
            }
            projmap.projecticalc(dtAsSeconds, window , playerOne, playerTwo, map, jfMilliseconds);
            map.checkmouse(window);
            playerOne.movement(dtAsSeconds, window, map, playerTwo);
            playerTwo.movement(dtAsSeconds, window, map, playerOne);

            window.clear();
            window.draw(s_background);
            
            for (int i = 0; i < map.tilevector.size(); i++) {
                
                window.draw(map.tilevector.at(i)->returnsprite());
            }
            for (int i = 0; i < projmap.projectilevector.size(); i++) {
                window.draw(projmap.projectilevector.at(i)->sprite);
            }
            
            window.draw(playerOne.getSprite());
            window.draw(playerTwo.getSprite());
            window.display();
        }

       
    }

}