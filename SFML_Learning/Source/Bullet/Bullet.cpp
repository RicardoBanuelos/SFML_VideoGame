#include "Bullet/Bullet.h"

#include <iostream>
#include <math.h>

#include "GameMath/GameMath.h"
#include "Zombie/Zombie.h"

#include "TextureLoader/TextureLoader.h"

Bullet::Bullet()
	:	GameObject(),
		mDamage(25.0f)
{
	init();
}

Bullet::~Bullet(){}

void Bullet::init()
{
	mID = BULLET;
	mSpeed = 10000.0f;
	mReleased = true;

	setTexture(TextureLoader::getTexture("Bullet"));
	initHitBox();
	alignCenter();
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

void Bullet::processCollision(ICollidable* other)
{
	Zombie* zombie = dynamic_cast<Zombie*>(other);
	if (!zombie) return;

	zombie->takeDamage(damage());

	release();
}

void Bullet::setAngle(float angle)
{
	calculateDirection(angle);
}

float Bullet::damage()
{
	return mDamage;
}

void Bullet::calculateDirection(float angle)
{
	float radians = GameMath::angleToRadians(getRotation());
	mDirection = sf::Vector2f(std::cos(radians), std::sinf(radians));
}