#include "engine.h"
using namespace sf;

engine::engine() 
{
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    background.loadFromFile("graphics/background.png");
    s_background.setTexture(background);
    
    
}
void engine::run() {
    {
        RenderWindow window(VideoMode(resolution.x, resolution.y), "Build N' Battle", Style::Default);
        playerOne.spawn(window);
        playerTwo.spawn(window);
        hud hud(window);

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
            animationtwo.calcanimationtwo(dtAsSeconds, playerTwo);
            animationone.calcanimationone(dtAsSeconds,playerOne);
            audio.calcaudioplayerone(window, playerOne);
            audio.calcaudioplayertwo(window, playerTwo);
            audio.calcaudiomap(map,projmap);
            window.clear();
            window.draw(s_background);
            hud.updatehud(window, playerOne, playerTwo);
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