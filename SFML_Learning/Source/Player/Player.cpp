#include "Player/Player.h"

#include <iostream>
#include <math.h>

#include "TextureLoader/TextureLoader.h"
#include "MousePosition/MousePosition.h"

Player::Player() {}

Player::Player(float x, float y, float width, float height, sf::Texture& texture)
	:	Character(x, y, width, height, texture)
{
	sf::Vector2i textureSize = mSprite.getTextureRect().getSize();

	mShape.setFillColor(sf::Color::Transparent);
	mShape.setOutlineColor(sf::Color::Red);
	mShape.setOutlineThickness(1.0f);
	mShape.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);

	mSprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);

	mBulletStartPoint.setSize(sf::Vector2f(10, 8));
}

Player::~Player() {}

void Player::update(float deltaTime)
{
	checkKeyInput(deltaTime);

	const float M_PI = 3.14159;
	const float offsetX = 115;
	const float offsetY = 52;

	float x2 = offsetX * cos(mShape.getRotation() * (M_PI / 180.0)) - offsetY * sin(mShape.getRotation() * (M_PI / 180.0));
	float y2 = offsetX * sin(mShape.getRotation() * (M_PI / 180.0)) + offsetY * cos(mShape.getRotation() * (M_PI / 180.0));

	float finalX = mShape.getPosition().x + x2;
	float finalY = mShape.getPosition().y + y2;

	mBulletStartPoint.setPosition(sf::Vector2f(finalX, finalY));

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
	window.draw(mShape);
	window.draw(mBulletStartPoint);
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

	mSprite.setRotation(angle);
	mShape.setRotation(angle);
	mBulletStartPoint.setRotation(angle);
}

void Player::shoot(float deltaTime)
{
	static float accumTime = 0;
	accumTime += deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && accumTime >= 0.4f)
	{
		accumTime = 0;
		sf::Vector2f mousePosition = MousePosition::get();

		std::cout << mBulletStartPoint.getPosition().x << " | " << mBulletStartPoint.getPosition().y << std::endl;

		Bullet bullet(mBulletStartPoint.getPosition().x, mBulletStartPoint.getPosition().y, 32, 32, mousePosition, TextureLoader::getTexture("Bullet"));
		bullet.setRotation(mBulletStartPoint.getRotation());
		mBullets.push_back(bullet);
	}
}
