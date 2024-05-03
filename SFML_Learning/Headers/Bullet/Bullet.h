#pragma once

#include "GameObject/GameObject.h"
#include "Collisions/ICollidable.h"

class Bullet : public GameObject, public ICollidable 
{
public:
	Bullet();
	Bullet(sf::Vector2f position, float angle, sf::Texture& texture);
	virtual ~Bullet();

	virtual void init() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void processCollision(ICollidable& other) override;

	void setAngle(float angle);

	void lateInit();
private:
	void calculateDirection(float angle);
	sf::Vector2f mDirection;
};