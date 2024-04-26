#include "Player/Player.h"

#include <iostream>
#include <math.h>

#include "TextureLoader/TextureLoader.h"
#include "MousePosition/MousePosition.h"
#include "GameMath/GameMath.h"

Player::Player() {}

Player::Player(sf::Vector2f position, const sf::Texture& texture)
	: GameObject(position, texture)
{
	mID = PLAYER;
}

Player::~Player() {}

void Player::update(float deltaTime)
{
	checkKeyInput(deltaTime);
	rotate();

	mBulletStartPoint.setPosition(getWeaponOffsetPosition(HANDGUN));
	shoot(deltaTime);

	for (Bullet& bullet : mBullets)
	{
		bullet.update(deltaTime);
	}
}

void Player::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);

	for (Bullet& bullet : mBullets)
	{
		bullet.draw(window);
	}
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
	mHitBox.move(direction * deltaTime);
}

void Player::rotate()
{
	sf::Vector2f mousePosition = MousePosition::get();
	float angle = atan2(mousePosition.y - getPosition().y, mousePosition.x - getPosition().x) * (180 / GameMath::PI);

	setRotation(angle);
	mBulletStartPoint.setRotation(angle);
	mHitBox.setRotation(angle);
}

void Player::shoot(float deltaTime)
{
	static float accumTime = 0;
	accumTime += deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && accumTime >= 0.4f)
	{
		accumTime = 0;

		sf::Vector2f startPoint(mBulletStartPoint.getPosition().x, mBulletStartPoint.getPosition().y);
		float angle = getRotation();

		mBullets.push_back(Bullet(startPoint, angle, TextureLoader::getTexture("Bullet")));
	}
}

sf::Vector2f Player::getWeaponOffsetPosition(WeaponID weapon)
{
	auto [offsetX, offsetY] = weaponOffsetsMap.at(weapon);
	
	float radians = GameMath::angleToRadians(getRotation());
	float x2 = offsetX * cos(radians) - offsetY * sin(radians);
	float y2 = offsetX * sin(radians) + offsetY * cos(radians);

	float finalX = getPosition().x + x2;
	float finalY = getPosition().y + y2;

	return sf::Vector2f(finalX, finalY);
}
