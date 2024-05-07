#include "Zombie/Zombie.h"
#include "Player/Player.h"
#include "GameMath/GameMath.h"

#include "TextureLoader/TextureLoader.h"
#include "GameObject/GameObjectHandler.h"

#include <iostream>

const float Zombie::OVERLAPPING_THRESHOLD = 150.0f;
const float Zombie::OVERLAPPING_FACTOR = -50.0f;

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
	mSpeed = 300.0f;
	setTexture(TextureLoader::getTexture(TextureData::TID_ZOMBIE_IDLE));
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
		}
	}

	std::unordered_set<GameObject*> otherZombies = GameObjectHandler::getByID(ZOMBIE);
	for (auto& otherZombie : otherZombies)
	{
		if (this == otherZombie) continue;
		sf::Vector2f direction = otherZombie->getPosition() - getPosition();
		float distance = sqrt(direction.x * direction.x + direction.y + direction.y);

		if (distance < OVERLAPPING_THRESHOLD)
		{
			direction = GameMath::normalize(direction);
			move(direction * (OVERLAPPING_FACTOR) * deltaTime);
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
