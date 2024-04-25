#include "Player/Player.h"

#include <iostream>

#include "TextureLoader/TextureLoader.h"
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
	checkKeyInput(deltaTime);
	rotate();
	shoot(deltaTime);

	for (Bullet& bullet : mBullets)
	{
		bullet.update(deltaTime);
	}

	Character::update(deltaTime); 
}

void Player::draw(sf::RenderWindow& window)
{
	Character::draw(window);

	for (Bullet& bullet : mBullets)
	{
		bullet.draw(window);
	}
}

void Player::move(sf::Vector2f direction)
{
	Character::move(direction);
}

void Player::checkKeyInput(float deltaTime)
{
	const float SPEED = 1000.0f;
	sf::Vector2f direction;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = sf::Vector2f(0, -SPEED);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = sf::Vector2f(-SPEED, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = sf::Vector2f(0, SPEED);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = sf::Vector2f(SPEED, 0);
	}

	move(direction * deltaTime);
}

void Player::rotate()
{
	sf::Vector2f mousePosition = MousePosition::get();
	float angle = atan2(mousePosition.y - mShape.getPosition().y, mousePosition.x - mShape.getPosition().x) * 180 / 3.14159265358979323846;

	mSprite.setRotation(angle - 20.0f);
}

void Player::shoot(float deltaTime)
{
	static float accumTime = 0;
	accumTime += deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && accumTime >= 0.4f)
	{
		accumTime = 0;
		sf::Vector2f mousePosition = MousePosition::get();

		Bullet bullet(mShape.getPosition().x, mShape.getPosition().y, 32, 32, mousePosition, TextureLoader::getTexture("Bullet"));
		mBullets.push_back(bullet);
	}
}