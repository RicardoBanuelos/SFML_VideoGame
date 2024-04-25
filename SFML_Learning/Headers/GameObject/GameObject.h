#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(float x, float y, float width, float height, sf::Texture& texture);
	virtual ~GameObject();

	virtual void update(float deltaTime);
	virtual void draw(sf::RenderWindow& window);

	sf::Vector2f position();
	sf::FloatRect globalBounds();
protected:
	sf::RectangleShape mShape;
	sf::Texture mTexture;
	sf::Sprite mSprite;
};