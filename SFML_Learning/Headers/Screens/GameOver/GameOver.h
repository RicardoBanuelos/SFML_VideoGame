#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include "Widgets/Button.h"

class GameOver {
public:
	GameOver(sf::RenderWindow& window);
	~GameOver();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	sf::Font mFont;
	sf::Text mTitle;
	sf::Text mMessage;

	int mWidth;
	int mHeight;
};