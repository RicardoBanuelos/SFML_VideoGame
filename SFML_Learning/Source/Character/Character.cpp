#include "Character/Character.h"

Character::Character(float x, float y, float width, float height, sf::Texture& texture)
	:	GameObject(x, y, width, height, texture)
{

}

Character::~Character()
{

}

void Character::update(float deltaTime)
{
	mSprite.setPosition(mShape.getPosition());
}

void Character::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Character::move(sf::Vector2f direction)
{
	mShape.move(direction);
}