#pragma once

#include "GameObject/GameObject.h"

class Bullet : public GameObject {
public:
	Bullet(sf::Vector2f position, sf::Vector2f size, sf::Vector2f target, sf::Texture& texture);
	~Bullet();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
private:
	const float SPEED;
	sf::Vector2f mDirection;
};