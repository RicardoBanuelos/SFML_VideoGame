#include "Player/Player.h"

Player::Player(float x, float y, float width, float height, sf::Texture& texture)
	:	Character(x, y, width, height, texture)
{
	mSprite.setTextureRect(sf::IntRect(64 * 6, 64 * 2, 64, 64));
}

Player::~Player() {}

void Player::update(float deltaTime)
{
	Character::update(deltaTime); 
}

void Player::draw(sf::RenderWindow& window)
{
	Character::draw(window);
}

void Player::move(sf::Vector2f direction)
{
	Character::move(direction);
}