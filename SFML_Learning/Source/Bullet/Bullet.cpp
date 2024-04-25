#include "Bullet//Bullet.h"

#include <iostream>
#include <math.h>

Bullet::Bullet(float x, float y, float width, float height, sf::Vector2f target, sf::Texture& texture)
	:	GameObject(x, y, width, height, texture),
		mDirection(target - sf::Vector2f(x, y))
{
	float magnitude = sqrt(mDirection.x * mDirection.x + mDirection.y * mDirection.y);
	mDirection.x /= magnitude;
	mDirection.y /= magnitude;
}

Bullet::~Bullet(){}

void Bullet::update(float deltaTime)
{
	const float SPEED = 100.0f;
	mShape.move(mDirection * SPEED * deltaTime);
	mSprite.setPosition(mShape.getPosition());
}

void Bullet::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Bullet::setRotation(float angle)
{
	mSprite.setRotation(angle);
}