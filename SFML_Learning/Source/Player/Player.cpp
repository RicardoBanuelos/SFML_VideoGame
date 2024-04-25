#include "Player/Player.h"

#include "MousePosition/MousePosition.h"

Player::Player() {}

Player::Player(float x, float y, float width, float height, sf::Texture& texture)
	:	Character(x, y, width, height, texture)
{
	sf::Vector2i textureSize = mSprite.getTextureRect().getSize();
	mSprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
}

Player::~Player() {}

void Player::update(float deltaTime)
{
	move(deltaTime);
	rotate(deltaTime);
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

void Player::move(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mShape.move(sf::Vector2f(0, -0.2));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mShape.move(sf::Vector2f(-0.2, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mShape.move(sf::Vector2f(0, 0.2));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mShape.move(sf::Vector2f(0.2, 0));
	}
}

void Player::rotate(float deltaTime)
{
	sf::Vector2f mousePosition = MousePosition::get();
	float angle = atan2(mousePosition.y - mShape.getPosition().y, mousePosition.x - mShape.getPosition().x) * 180 / 3.14159265358979323846;

	mSprite.setRotation(angle - 20.0f);
}

void Player::shoot(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{

	}
}