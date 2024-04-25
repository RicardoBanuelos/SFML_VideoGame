#include "Bullet//Bullet.h"

#include <iostream>
#include <math.h>

Bullet::Bullet(float x, float y, float width, float height, sf::Vector2f target, sf::Texture& texture)
	:	GameObject(x, y, width, height, texture),
		SPEED(0.5f),
		mDirection(target - sf::Vector2f(x, y))
{
	mSprite.setTextureRect(sf::IntRect(16 * 0, 16 * 0, 16, 16));

	float magnitude = sqrt(mDirection.x * mDirection.x + mDirection.y * mDirection.y);
	mDirection.x /= magnitude;
	mDirection.y /= magnitude;
}

Bullet::~Bullet(){}

void Bullet::update(float timeDelta)
{
	mShape.move(mDirection * SPEED);
	mSprite.setPosition(mShape.getPosition());
}

void Bullet::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}