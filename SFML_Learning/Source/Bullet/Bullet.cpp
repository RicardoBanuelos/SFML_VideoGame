#include "Bullet/Bullet.h"

#include <iostream>
#include <math.h>

#include "GameMath/GameMath.h"

Bullet::Bullet(sf::Vector2f position, float angle, sf::Texture& texture)
	:	GameObject(position, texture)
{
	mID = BULLET;
	setRotation(angle);
	calculateDirection(angle);
}

Bullet::~Bullet(){}

void Bullet::update(float deltaTime)
{
	const float SPEED = 1000.0f;
	move(mDirection * SPEED * deltaTime);
}

void Bullet::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Bullet::calculateDirection(float angle)
{
	float radians = GameMath::angleToRadians(getRotation());
	mDirection = sf::Vector2f(std::cos(radians), std::sinf(radians));
}