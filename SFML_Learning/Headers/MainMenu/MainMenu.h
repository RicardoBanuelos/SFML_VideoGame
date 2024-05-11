#pragma once

#include <SFML/Graphics.hpp>
#include "Widgets/Button.h"

class MainMenu {
public:
	MainMenu(sf::RenderWindow& window);
	~MainMenu();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	sf::Font mFont;

	sf::Text mTitle;
	
	Button* mPlayButton;
	Button* mExitButton;

	int mWidth;
	int mHeight;
};