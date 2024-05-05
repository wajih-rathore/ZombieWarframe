#include "Game.h"

Game::Game() : window(sf::VideoMode(1280, 720), "Plants Vs Zombies"), isDragging(false) {
    // Game icon
    sf::Image icon;
    if (!icon.loadFromFile("Images/icon.png")) {
        // Handle error
    }
    window.setIcon(32, 32, icon.getPixelsPtr());
}

void Game::run() {
    const int ROWS = 5;
    const int COLS = 9;

        Texture zombieTexture;
        Sprite zombieSprite;
        zombieTexture.loadFromFile("Images/Zombie_0.png");
        zombieSprite.setTexture(zombieTexture);
        zombieSprite.setPosition(490, 540);
        zombieSprite.setScale(0.8f, 0.8f);

        // Set the origin to the center of the sprite
        zombieSprite.setOrigin(zombieSprite.getLocalBounds().width / 2, zombieSprite.getLocalBounds().height / 2);


    while (window.isOpen()) {
        float time = timeMoney.getElapsedTime().asMicroseconds();
        float moneyTime = timeMoney.getElapsedTime().asSeconds();
        time = time / 800;

        sf::Event event;
        while (window.pollEvent(event)) {
            handleWindowCloseEvent(window, event);
            handleMousePressedEvent(window, event, zombieSprite, isDragging);
            handleMouseReleasedEvent(window, event, isDragging);
        }

        handleDragging(window, zombieSprite);

        createBack(window);
        drawGridWithHoverHighlight(window);

        window.draw(sunflowerCardSprite);
        window.draw(peashooterCardSprite);
        window.draw(zombieSprite);
        peashooter.draw(window);
        sun.draw(window);
        sun.moveSun();

        window.setSize(sf::Vector2u(1280, 720));
        window.display();
    }
}

void Game::createBack(sf::RenderWindow& window) {
    sf::Image map_image;
    map_image.loadFromFile("Images/background.png");
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(0, 0);

    window.draw(s_map);
}

void Game::drawGridWithHoverHighlight(sf::RenderWindow& window) {
    const int ROWS = 5;
    const int COLS = 9;
    const int CELL_WIDTH = 90;
    const int CELL_HEIGHT = 110;
    const int START_X = 230;
    const int START_Y = 120;

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sf::RectangleShape cell(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
            cell.setPosition(START_X + j * CELL_WIDTH, START_Y + i * CELL_HEIGHT);
            cell.setFillColor(sf::Color::Transparent);
            cell.setOutlineThickness(0.f);
            cell.setOutlineColor(sf::Color::Transparent);
            if (cell.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                cell.setFillColor(sf::Color(255, 255, 255, 100));
            }
            window.draw(cell);
        }
    }
}

void Game::createMap(sf::RenderWindow& window) {
    sf::Image map_image;
    map_image.loadFromFile("Images/grid2.png");
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(100, 100);

    window.draw(s_map);
}

void Game::displayMouseCoordinates(sf::RenderWindow& window, sf::Font& font) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Text mousePosText;
    mousePosText.setFont(font);
    mousePosText.setCharacterSize(24);
    mousePosText.setFillColor(sf::Color::White);
    mousePosText.setString("Mouse position: " + std::to_string(mousePos.x) + ", " + std::to_string(mousePos.y));
    mousePosText.setPosition(window.getSize().x - mousePosText.getLocalBounds().width - 10, 10);
    window.draw(mousePosText);
}


void Game::handleWindowCloseEvent(sf::RenderWindow& window, sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}

void Game::handleMousePressedEvent(sf::RenderWindow& window, sf::Event& event, sf::Sprite& zombieSprite, bool& isDragging) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (zombieSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                isDragging = true;
            }
        }
    }
}

void Game::handleMouseReleasedEvent(sf::RenderWindow& window, sf::Event& event, bool& isDragging) {
    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            isDragging = false;
        }
    }
}


void Game::handleDragging(sf::RenderWindow& window, sf::Sprite& zombieSprite) {
    if (isDragging) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        zombieSprite.setPosition(mousePos.x, mousePos.y);
    }
}