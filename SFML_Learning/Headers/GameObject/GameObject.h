#pragma once

#include "GameObjectIDs.h"

#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite {
public:
	GameObject();
	GameObject(sf::Vector2f position, const sf::Texture& texture);
	virtual ~GameObject();

	virtual void update(float deltaTime);
	virtual void draw(sf::RenderWindow& window);

protected:
	ID mID;
	sf::RectangleShape mHitBox;
	float mSpeed;

private:
	void initHitBox();
	void alignCenter();
};