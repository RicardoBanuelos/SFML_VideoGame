#include "MousePosition/MousePosition.h"

sf::Vector2f MousePosition::mMousePosition;

void MousePosition::update(sf::RenderWindow& window)
{
	sf::Vector2i mousePixelCoords = sf::Mouse::getPosition(window);
	mMousePosition = window.mapPixelToCoords(mousePixelCoords);
}

sf::Vector2f MousePosition::get()
{
	return mMousePosition;
}