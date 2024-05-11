#pragma once

#include<SFML/Graphics.hpp>
using namespace sf;

class PauseScreen
{
	Texture menuButtonTexture;
	Sprite menuButtonSprite;
	Texture resumeButtonTexture;
	Sprite resumeButtonSprite;
	Texture dimScreenTexture;
	Sprite dimScreenSprite;

public:
	PauseScreen();
	void drawPauseScreen(RenderWindow&);
	Sprite getMenuButton();
	Sprite getResumeButton();


};

