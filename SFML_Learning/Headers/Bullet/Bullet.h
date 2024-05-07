#pragma once

#include "GameObject/GameObject.h"
#include "Collisions/ICollidable.h"

class Bullet : public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	virtual void init() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void processCollision(ICollidable* other) override;

	void setAngle(float angle);
	float damage();
private:
	void calculateDirection(float angle);

	sf::Vector2f mDirection;
	float mDamage;
};