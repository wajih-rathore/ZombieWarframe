#include <SFML/Graphics.hpp>
#include "Game.h"

void main() 
{
    Game game;
    game.run();
}


























//#include <SFML/Graphics.hpp>
//#include <ctime>
//#include"Peashooter.h"
//#include"Sun.h"
////#include"../SFML/Images/"
//using namespace sf;
//using namespace std;
//
//
//struct coordinates {
//	int x;
//	int y;
//};
//
//void displayMouseCoordinates(RenderWindow& window, Font& font) {
//	// Get the current mouse position
//	Vector2i mousePos = Mouse::getPosition(window);
//
//	// Create a text object
//	Text mousePosText;
//	mousePosText.setFont(font);
//	mousePosText.setCharacterSize(24); // Set the size of the text
//	mousePosText.setFillColor(Color::White); // Set the color of the text
//
//	// Update the text object
//	mousePosText.setString("Mouse position: " + std::to_string(mousePos.x) + ", " + std::to_string(mousePos.y));
//	mousePosText.setPosition(window.getSize().x - mousePosText.getLocalBounds().width - 10, 10); // Position the text in the top right corner, with a small margin
//
//	// Draw the text object
//	window.draw(mousePosText);
//}
//
//
//// Add this function to your code
//void drawGridWithHoverHighlight(RenderWindow& window) {
//	const int ROWS = 5;
//	const int COLS = 9;
//	const int CELL_WIDTH = 90; // Change this to adjust cell width
//	const int CELL_HEIGHT = 110; // Change this to adjust cell height
//	const int START_X = 230;
//	const int START_Y = 120;
//
//	// Get the current mouse position in the window
//	Vector2i mousePos = Mouse::getPosition(window);
//
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			RectangleShape cell(Vector2f(CELL_WIDTH, CELL_HEIGHT));
//			cell.setPosition(START_X + j * CELL_WIDTH, START_Y + i * CELL_HEIGHT);
//
//			// Set cell to be transparent with thin borders
//			cell.setFillColor(Color::Transparent);
//			cell.setOutlineThickness(0.f); // Adjust this to change border thickness
//			cell.setOutlineColor(Color::Transparent);
//
//			// Check if the mouse is inside this cell
//			if (cell.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//				cell.setFillColor(Color(255, 255, 255, 100)); // Highlight color
//			}
//
//			window.draw(cell);
//		}
//	}
//}
////Drawing the background
//void createBack(RenderWindow& window) {
//	//Drawing the background
//	Image map_image;
//	map_image.loadFromFile("Images/background.png");
//	Texture map;
//	map.loadFromImage(map_image);
//	Sprite s_map;
//	s_map.setTexture(map);
//	s_map.setPosition(0, 0);
//
//	//drawGridWithHoverHighlight(window);
//	window.draw(s_map);
//}
////Drawing the map
//void createMap(RenderWindow& window) {
//	//Drawing a map
//	Image map_image;//объект изображения для карты
//	map_image.loadFromFile("Images/grid2.png");//load the file for the map
//	Texture map;
//	map.loadFromImage(map_image);
//	Sprite s_map;
//	s_map.setTexture(map);
//	s_map.setPosition(100, 100);
//
//	/*drawGridWithHoverHighlight(window);*/
//
//	window.draw(s_map);
//}
//
//int main()
//{
//	//Create a window, n*n
//	RenderWindow window(VideoMode(1280, 720), "Plants Vs Zombies");
//	//Game icon
//	Image icon;
//	if (!icon.loadFromFile("Images/icon.png"))
//	{
//		return 1;
//	}
//	window.setIcon(32, 32, icon.getPixelsPtr());
//
//	///////////////////////////////////////
//
//	//Game field (5*9)
//	//Point 137*79 - leftmost point
//	//length 41; width 53
//	const int ROWS = 5;
//	const int COLS = 9;
//
//	bool FIELD_GAME_STATUS[ROWS][COLS];
//
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			FIELD_GAME_STATUS[i][j] = true;
//		}
//	}
//
//	Clock timeMoney;
//	Event event;
//
//	//Texture peaShooterTexture;
//	//Sprite peaShooterSprite;
//	//peaShooterTexture.loadFromFile("Images/pea-shooter.gif");
//	//peaShooterSprite.setTexture(peaShooterTexture);
//	//peaShooterSprite.setPosition(500, 500);
//
//	Texture sunflowerCardTexture;
//	Sprite sunflowerCardSprite;
//	sunflowerCardTexture.loadFromFile("Images/card_sunflower.png");
//	sunflowerCardSprite.setTexture(sunflowerCardTexture);
//	sunflowerCardSprite.setPosition(10, 25);
//	sunflowerCardSprite.setScale(1.2, 1.2);
//
//	Texture peashooterCardTexture;
//	Sprite peashooterCardSprite;
//	peashooterCardTexture.loadFromFile("Images/card_peashooter.png");
//	peashooterCardSprite.setTexture(peashooterCardTexture);
//	peashooterCardSprite.setPosition(10, 145);
//	peashooterCardSprite.setScale(1.2, 1.2);
//
//	Texture zombieTexture;
//	Sprite zombieSprite;
//	zombieTexture.loadFromFile("Images/Zombie_0.png");
//	zombieSprite.setTexture(zombieTexture);
//	zombieSprite.setPosition(490, 540);
//	zombieSprite.setScale(0.8f, 0.8f);
//
//	// Set the origin to the center of the sprite
//	zombieSprite.setOrigin(zombieSprite.getLocalBounds().width / 2, zombieSprite.getLocalBounds().height / 2);
//
//	Clock clock;
//	Peashooter peashooter;
//	bool isDragging = false;
//	
//	Sun sun;
//	while (window.isOpen())
//	{
//		float time = clock.getElapsedTime().asMicroseconds();
//		float moneyTime = timeMoney.getElapsedTime().asSeconds();
//
//		clock.restart();
//		time = time / 800;
//
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//			if (event.type == Event::MouseButtonPressed)
//			{
//				if (event.mouseButton.button == Mouse::Left)
//				{
//					Vector2i mousePos = Mouse::getPosition(window);
//					if (zombieSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
//					{
//						isDragging = true;
//					}
//				}
//			}
//
//			if (event.type == Event::MouseButtonReleased)
//			{
//				if (event.mouseButton.button == Mouse::Left)
//				{
//					isDragging = false;
//				}
//			}
//
//
//			if (isDragging)
//			{
//				Vector2i mousePos = Mouse::getPosition(window);
//				zombieSprite.setPosition(mousePos.x, mousePos.y);
//			}
//
//		}
//
//
//
//		createBack(window);
//		drawGridWithHoverHighlight(window);
//
//		window.draw(sunflowerCardSprite);
//		window.draw(peashooterCardSprite);
//		window.draw(zombieSprite);
//		peashooter.draw(window);
//		sun.draw(window);
//		sun.moveSun();
//		
//
//		window.setSize(sf::Vector2u(1280, 720));
//		window.display();
//	}
//
//
//	return 0;
//}