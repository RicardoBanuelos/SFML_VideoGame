#pragma once

#include "GameObject/GameObject.h"

class Bullet : public GameObject {
public:
	Bullet(float x, float y, float width, float height, sf::Vector2f target, sf::Texture& texture);
	virtual ~Bullet();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
private:
	const float SPEED;
	sf::Vector2f mDirection;
};