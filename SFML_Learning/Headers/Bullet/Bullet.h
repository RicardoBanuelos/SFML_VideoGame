#pragma once

#include "GameObject/GameObject.h"

class Bullet : public GameObject {
public:
	Bullet();
	Bullet(sf::Vector2f position, float angle, sf::Texture& texture);
	virtual ~Bullet();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;

	void setAngle(float angle);
private:
	void calculateDirection(float angle);

	sf::Vector2f mDirection;
};