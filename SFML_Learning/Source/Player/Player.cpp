#include "Player/Player.h"

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Texture& texture)
	:	Character(position, size, texture)
{
	mSprite.setTextureRect(sf::IntRect(64 * 6, 64 * 2, 64, 64));
}

Player::~Player() {}

void Player::update(float deltaTime)
{
	
}

void Player::draw(sf::RenderWindow& window)
{
	Character::draw(window);
}

void Player::move(sf::Vector2f direction)
{
	Character::move(direction);
}