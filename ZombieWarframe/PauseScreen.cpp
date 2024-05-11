#include "PauseScreen.h"

PauseScreen::PauseScreen()
{
	menuButtonTexture.loadFromFile("../Images/menubutton.png");
	menuButtonSprite.setTexture(menuButtonTexture);
	menuButtonSprite.setPosition(550, 250);
	menuButtonSprite.setScale(0.4, 0.4);

	resumeButtonTexture.loadFromFile("../Images/resumeButton.png");
	resumeButtonSprite.setTexture(resumeButtonTexture);
	resumeButtonSprite.setPosition(550, 350);
	resumeButtonSprite.setScale(0.4, 0.4);

	dimScreenTexture.loadFromFile("../Images/blackcast.png");
	dimScreenSprite.setTexture(dimScreenTexture);
	dimScreenSprite.setPosition(0, 0);
	dimScreenSprite.setScale(10, 10);

}

void PauseScreen::drawPauseScreen(RenderWindow &window)
{
	window.draw(dimScreenSprite);
	window.draw(resumeButtonSprite);
	window.draw(menuButtonSprite);
}

Sprite PauseScreen::getMenuButton()
{
	return menuButtonSprite;
}

Sprite PauseScreen::getResumeButton()
{
	return resumeButtonSprite;
}


