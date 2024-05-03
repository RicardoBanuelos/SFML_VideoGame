#include "Zombie/Zombie.h"

Zombie::Zombie()
	:	GameObject()
{
	mID = ZOMBIE;
	mSpeed = 900.0f;
}

Zombie::Zombie(sf::Vector2f position, const sf::Texture& texture)
	:	GameObject(position, texture)
{
	mID = ZOMBIE;
	mSpeed = 900.0f;
}

Zombie::~Zombie() {}

void Zombie::update(float deltaTime)
{
	GameObject::update(deltaTime);
}

void Zombie::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}
