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
    bool celloccupied[5][9] = { false };

    Texture zombieTexture;
    Sprite zombieSprite;
    zombieTexture.loadFromFile("Images/Zombie_0.png");
    zombieSprite.setTexture(zombieTexture);
    zombieSprite.setPosition(490, 540);
    zombieSprite.setScale(0.8f, 0.8f);
    zombieSprite.setOrigin(zombieSprite.getLocalBounds().width / 2, zombieSprite.getLocalBounds().height / 2);

    //plantFactory->Peashooter();
    

	Texture peashooterCardTexture;
	Sprite peashooterCardSprite;
	peashooterCardTexture.loadFromFile("Images/card_peashooter.png");
	peashooterCardSprite.setTexture(peashooterCardTexture);
	peashooterCardSprite.setPosition(10, 145);
	peashooterCardSprite.setScale(1.2, 1.2);
    bool isPeashooterSelected = false;

    while (window.isOpen()) {
        float time = timeMoney.getElapsedTime().asMicroseconds();
        float moneyTime = timeMoney.getElapsedTime().asSeconds();
        time = time / 800;

        
        
        Event event;

        while (window.pollEvent(event))
        {
            handleWindowCloseEvent(window, event);
           // handleMousePressedEvent(window, event, zombieSprite);
            //handleMouseReleasedEvent(window, event);
            //placePeashooter(window, event, peashooterCardSprite, isPeashooterSelected);

            Vector2i mousePosition = Mouse::getPosition(window);
            
            
            if (event.type == Event::MouseButtonPressed)
            {
                cout << "Mouse presses"<<endl;

                for (int i = 0; i <5; i++) {
                    for (int j = 0; j < 9; j++) {
                        cout << celloccupied[i][j] << " ";
					
                    }
                    cout<< endl;
                }
                int column = ((mousePosition.x - 230) / 90) + 1;
                int row = ((mousePosition.y - 120) / 110) + 1;
                if( ( (mousePosition.x > 230 && mousePosition.x < 1040)  && (mousePosition.y > 120 && mousePosition.y < 670) ) && !celloccupied[row-1][column-1])
				{
				    cout << "Row: " << row<< " Column: " << column<< endl;
                    plantFactory.createPeashooter(row, column);
				    	celloccupied[row-1][column-1] = true;
				}
            }
        }

        handleDragging(window, zombieSprite);

        createBack(window);
        drawGridWithHoverHighlight(window);

        window.draw(peashooterCardSprite);
        window.draw(zombieSprite);
        //peashooter.draw(window);
        plantFactory.draw(window);
        sun.draw(window);
        sun.moveSun();

        window.setSize(sf::Vector2u(1280, 720));
        window.display();
    }
}

void Game::createBack(RenderWindow& window) {
    sf::Image map_image;
    map_image.loadFromFile("Images/background.png");
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(0, 0);

    window.draw(s_map);
}

void Game::drawGridWithHoverHighlight(RenderWindow& window) {
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

void Game::createMap(RenderWindow& window) {
    sf::Image map_image;
    map_image.loadFromFile("Images/grid2.png");
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(100, 100);

    window.draw(s_map);
}

void Game::displayMouseCoordinates(RenderWindow& window, Font& font) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Text mousePosText;
    mousePosText.setFont(font);
    mousePosText.setCharacterSize(24);
    mousePosText.setFillColor(sf::Color::White);
    mousePosText.setString("Mouse position: " + std::to_string(mousePos.x) + ", " + std::to_string(mousePos.y));
    mousePosText.setPosition(window.getSize().x - mousePosText.getLocalBounds().width - 10, 10);
    window.draw(mousePosText);
}

void Game::handleWindowCloseEvent(RenderWindow& window, Event& event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}

void Game::handleMousePressedEvent(RenderWindow& window, Event& event, Sprite& zombieSprite) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (zombieSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                isDragging = true;
            }
        }
    }
}

void Game::handleMouseReleasedEvent(RenderWindow& window, Event& event) {
    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            isDragging = false;
        }
    }
}

void Game::handleDragging(RenderWindow& window, Sprite& zombieSprite) {
    if (isDragging) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        zombieSprite.setPosition(mousePos.x, mousePos.y);
    }
}

void Game::placePeashooter(RenderWindow& window, Event& event,Sprite& peashooterCardSprite, bool& isPeashooterSelected) 
{
	if (event.mouseButton.button == Mouse::Left)
	{
		Vector2i mousePos = Mouse::getPosition(window);

		if (peashooterCardSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			isPeashooterSelected = true;
		}
		else if (isPeashooterSelected) {
			//peashooter.createPeashooter(mousePos.x, mousePos.y);
			isPeashooterSelected = false;
		}

	}
}