#include "Zombie/Zombie.h"
#include "Player/Player.h"
#include "GameMath/GameMath.h"

#include <iostream>

Zombie::Zombie()
	:	GameObject(),
		mPlayer(nullptr),
		mAttackDelay(0.0f)
{
	init();
}

Zombie::Zombie(sf::Vector2f position, const sf::Texture& texture)
	:	GameObject(position, texture),
		mPlayer(nullptr),
		mAttackDelay(0.0f)
{
	init();;
}

Zombie::Zombie(sf::Vector2f position, const sf::Texture & texture, Player * player)
	:	GameObject(position, texture),
		mPlayer(player),
		mAttackDelay(0.0f)
{
	init();
}

Zombie::~Zombie() {}

void Zombie::init()
{
	mID = ZOMBIE;
	mSpeed = 200.0f;
}

void Zombie::update(float deltaTime)
{
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
			std::cout << "Zombie Collision" << std::endl;
		}
	}

	GameObject::update(deltaTime);
}

void Zombie::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Zombie::processCollision(ICollidable& other)
{
	
}

void Zombie::setPlayer(Player* player)
{
	mPlayer = player;
}
