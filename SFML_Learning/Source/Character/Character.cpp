#include "Character/Character.h"

Character::Character(sf::Vector2f position, sf::Vector2f size, sf::Texture& texture)
	:	GameObject(position, size, texture)
{

}

Character::~Character()
{

}

void Character::update(float deltaTime)
{

}

void Character::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Character::move(sf::Vector2f direction)
{
	mPosition += direction;
	mSprite.setPosition(mPosition);
}