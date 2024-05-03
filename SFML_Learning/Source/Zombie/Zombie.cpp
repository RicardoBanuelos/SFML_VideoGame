#include "Zombie/Zombie.h"
#include "Player/Player.h"
#include "GameMath/GameMath.h"

#include <iostream>

Zombie::Zombie()
	:	GameObject(),
		mPlayer(nullptr)
{
	init();
}

Zombie::Zombie(sf::Vector2f position, const sf::Texture& texture)
	:	GameObject(position, texture),
		mPlayer(nullptr)
{
	init();;
}

Zombie::Zombie(sf::Vector2f position, const sf::Texture & texture, Player * player)
	:	GameObject(position, texture),
		mPlayer(player)
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
	if (mPlayer)
	{
		sf::Vector2f direction = mPlayer->getPosition() - getPosition();
		direction = GameMath::normalize(direction);

		float angle = std::atan2(direction.y, direction.x) * 180 / GameMath::PI;

		move(mSpeed * direction * deltaTime);
		setRotation(angle);
	}

	GameObject::update(deltaTime);
}

void Zombie::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Zombie::processCollision(ICollidable& other)
{
	std::cout << "Zombie Collision" << std::endl;
}

void Zombie::setPlayer(Player* player)
{
	mPlayer = player;
}
