#include "PlayerOne.h"
#include "PlayerTwo.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(resolution.x, resolution.y), "Final Project", Style::Default);
    Texture background;
    background.loadFromFile("graphics/background.png");
    Sprite s_background;
    s_background.setTexture(background);

    PlayerOne playerOne;
    PlayerTwo playerTwo;
    playerOne.spawn(window);
    playerTwo.spawn(window);

    Clock clock;

    while(window.isOpen())
    {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }

        playerOne.movement(dtAsSeconds, window);
        playerTwo.movement(dtAsSeconds, window);

        window.clear();
        window.draw(s_background);
        window.draw(playerOne.getSprite());
        window.draw(playerTwo.getSprite());
        window.display();
    }

    return 0;
}