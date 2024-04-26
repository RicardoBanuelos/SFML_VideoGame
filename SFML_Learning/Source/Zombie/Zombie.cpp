#include "Zombie/Zombie.h"

Zombie::Zombie()
	:	GameObject()
{
}

Zombie::Zombie(sf::Vector2f position, const sf::Texture& texture)
	:	GameObject(position, texture)
{
}

Zombie::~Zombie() {}

void Zombie::update(float deltaTime)
{

}

void Zombie::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}
