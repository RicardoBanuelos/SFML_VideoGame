#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(sf::Vector2f position, sf::Vector2f size, sf::Texture& texture);
	virtual ~GameObject();

	virtual void update(float deltaTime);
	virtual void draw(sf::RenderWindow& window);
protected:
	sf::Vector2f mPosition;
	sf::Vector2f mSize;
	sf::Sprite mSprite;
};