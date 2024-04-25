#pragma once

#include <SFML/Graphics.hpp>

class MousePosition {
public:
	MousePosition() = delete;
	static void update(sf::RenderWindow& window);
	static sf::Vector2f get();
private:
	static sf::Vector2f mMousePosition;
};