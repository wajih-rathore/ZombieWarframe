#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Peashooter.h"
#include "Sun.h"
#include "PlantFactory.h"
using namespace sf;
using namespace std;

class Game {
public:
    Game();
    void run();

private:

    RenderWindow window;
    PlantFactory plantFactory;
    Clock timeMoney;
    Sprite peashooterCardSprite;
    Sprite zombieSprite;
    Sun sun;

    bool isDragging;
    bool celloccupied[5][9] = { false };
    static int plantType;

    void displayMouseCoordinates(sf::RenderWindow& window, sf::Font& font);
    void drawGridWithHoverHighlight(sf::RenderWindow& window);
    void createBack(sf::RenderWindow& window);
    void createMap(sf::RenderWindow& window);
    void handleWindowCloseEvent(sf::RenderWindow& window, sf::Event& event);
    void handleMousePressedEvent(sf::RenderWindow& window, sf::Event& event, sf::Sprite& zombieSprite);
    void handleMouseReleasedEvent(sf::RenderWindow& window, sf::Event& event);
    void handleDragging(sf::RenderWindow& window, sf::Sprite& zombieSprite);
    void placePeashooter(sf::RenderWindow& window, sf::Event& event, sf::Sprite& peashooterCardSprite, bool& isPeashooterSelected);
    void createPlantOfType(sf::Event& event, sf::Vector2i& mousePosition);
    void drawCardsTextureAndSprite(RenderWindow& window);
    int checkSelectedPlant(sf::Vector2i& mousePosition);
    bool isPlantCardSelected(sf::Vector2i& mousePosition);


};
