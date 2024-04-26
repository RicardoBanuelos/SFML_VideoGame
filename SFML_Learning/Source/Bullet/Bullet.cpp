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

	sf::Vector2i textureSize = mSprite.getTextureRect().getSize();

	mShape.setFillColor(sf::Color::Transparent);
	mShape.setOutlineColor(sf::Color::Red);
	mShape.setOutlineThickness(1.0f);
	mShape.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);

	mSprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
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
	window.draw(mShape);
	GameObject::draw(window);
}

void Bullet::setRotation(float angle)
{
	mSprite.setRotation(angle);
	float angleInRadians = mSprite.getRotation() * (3.14159265f / 180.f);
	mDirection = sf::Vector2f(std::cos(angleInRadians), std::sinf(angleInRadians));
}