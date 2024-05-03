#include "Bullet/Bullet.h"

#include <iostream>
#include <math.h>

#include "GameMath/GameMath.h"

Bullet::Bullet()
{
	init();
}

Bullet::Bullet(sf::Vector2f position, float angle, sf::Texture& texture)
	:	GameObject(position, texture)
{
	init();
	setRotation(angle);
	calculateDirection(angle);
}

Bullet::~Bullet(){}

void Bullet::init()
{
	mID = BULLET;
	mSpeed = 10000.0f;
}

void Bullet::update(float deltaTime)
{
	move(mDirection * mSpeed * deltaTime);

	if (GameMath::outOfBounds(getPosition().x, getPosition().y))
	{
		release();
	}

	GameObject::update(deltaTime);
}

void Bullet::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Bullet::processCollision(ICollidable& other)
{

}

void Bullet::setAngle(float angle)
{
	calculateDirection(angle);
}

void Bullet::lateInit()
{
	initHitBox();
	alignCenter();
}

void Bullet::calculateDirection(float angle)
{
	float radians = GameMath::angleToRadians(getRotation());
	mDirection = sf::Vector2f(std::cos(radians), std::sinf(radians));
}