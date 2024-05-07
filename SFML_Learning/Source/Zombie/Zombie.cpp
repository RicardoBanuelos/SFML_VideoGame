#include "Zombie/Zombie.h"
#include "Player/Player.h"
#include "GameMath/GameMath.h"

#include "TextureLoader/TextureLoader.h"

#include <iostream>

Zombie::Zombie()
	:	GameObject(),
		mPlayer(nullptr),
		mAttackDelay(0.0f),
		mHealth(100.0f),
		mDamage(25.0f)
{
	init();
}

Zombie::Zombie(sf::Vector2f position)
	:	GameObject(position),
		mPlayer(nullptr),
		mAttackDelay(0.0f),
		mHealth(100.0f),
		mDamage(25.0f)
{
	init();
}

Zombie::~Zombie() {}

void Zombie::init()
{
	mID = ZOMBIE;
	mSpeed = 200.0f;
	setTexture(TextureLoader::getTexture("Zombie"));
	initHitBox();
	alignCenter();
}

void Zombie::update(float deltaTime)
{
	if (mHealth == 0)
	{
		release();
		return;
	}

	mAttackDelay += deltaTime;

	if (mPlayer)
	{
		sf::Vector2f direction = mPlayer->getPosition() - getPosition();
		direction = GameMath::normalize(direction);

		float angle = std::atan2(direction.y, direction.x) * 180 / GameMath::PI;

		move(mSpeed * direction * deltaTime);
		setRotation(angle);

		if (GameMath::isColliding(getGlobalBounds(), mPlayer->getGlobalBounds()) && mAttackDelay >= 1.0f)
		{
			mAttackDelay = 0.0f;
			mPlayer->takeDamage(damage());
			std::cout << "HP: " << mPlayer->health() << std::endl;
		}
	}

	GameObject::update(deltaTime);
}

void Zombie::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Zombie::processCollision(ICollidable* other)
{
	
}

void Zombie::takeDamage(float damage)
{
	mHealth = GameMath::clamp(0, 100, mHealth - damage);
}

float Zombie::damage()
{
	return mDamage;
}

void Zombie::setPlayer(Player* player)
{
	mPlayer = player;
}
