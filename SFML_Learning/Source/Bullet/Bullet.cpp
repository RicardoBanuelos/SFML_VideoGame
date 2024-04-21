#include "Bullet//Bullet.h"

#include <math.h>

Bullet::Bullet(sf::Vector2f position, sf::Vector2f size, sf::Vector2f target, sf::Texture& texture)
	:	GameObject(position, size, texture),
		SPEED(0.5f),
		mDirection(target - position)
{
	mSprite.setTextureRect(sf::IntRect(16 * 0, 16 * 0, 16, 16));

	float magnitude = sqrt(mDirection.x * mDirection.x + mDirection.y * mDirection.y);
	mDirection.x /= magnitude;
	mDirection.y /= magnitude;
}

Bullet::~Bullet(){}

void Bullet::update(float timeDelta)
{
	mPosition += (mDirection * SPEED);
	mSprite.setPosition(mPosition);
}

void Bullet::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}