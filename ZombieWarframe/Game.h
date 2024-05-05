#pragma once
#include <SFML/Graphics.hpp>
#include "Peashooter.h"
#include "Sun.h"
using namespace sf;

class Game {
public:
    Game();
    void run();

private:
    void displayMouseCoordinates(sf::RenderWindow& window, sf::Font& font);
    void drawGridWithHoverHighlight(sf::RenderWindow& window);
    void createBack(sf::RenderWindow& window);
    void createMap(sf::RenderWindow& window);

    void handleWindowCloseEvent(sf::RenderWindow& window, sf::Event& event);
    void handleMousePressedEvent(sf::RenderWindow& window, sf::Event& event, sf::Sprite& zombieSprite, bool& isDragging);
    void handleMouseReleasedEvent(sf::RenderWindow& window, sf::Event& event, bool& isDragging);
    void handleDragging(sf::RenderWindow& window, sf::Sprite& zombieSprite);


    RenderWindow window;
    Clock timeMoney;
    Sprite sunflowerCardSprite;
    Sprite peashooterCardSprite;
    Sprite zombieSprite;
    Peashooter peashooter;
    Sun sun;
    bool isDragging;
};
