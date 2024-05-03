#include "Player/Player.h"

#include <iostream>
#include <math.h>

#include "TextureLoader/TextureLoader.h"
#include "MousePosition/MousePosition.h"
#include "GameMath/GameMath.h"

#include "ObjectPool/ObjectPoolHandler.h"
#include "GameObject/GameObjectHandler.h"

Player::Player(sf::Vector2f position, const sf::Texture& texture)
	:	GameObject(position, texture)
{
	init();
}

Player::~Player() 
{}

void Player::init()
{
	mID = PLAYER;
	mSpeed = 1000.0f;
}

void Player::update(float deltaTime)
{
	checkKeyInput(deltaTime);
	rotate();

	mBulletStartPoint.setPosition(getWeaponOffsetPosition(HANDGUN));
	shoot(deltaTime);

	GameObject::update(deltaTime);
}

void Player::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Player::processCollision(ICollidable& other)
{
	std::cout << "Player Collision" << std::endl;
}

void Player::checkKeyInput(float deltaTime)
{
	sf::Vector2f direction;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction.x = 1;
	}

	direction = GameMath::normalize(direction);

	move(mSpeed * direction * deltaTime);
	mHitBox.move(mSpeed * direction * deltaTime);
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && accumTime >= 0.25f)
	{
		accumTime = 0; 

		Bullet* bullet = ObjectPoolHandler::acquireBullet();
		bullet->setPosition(mBulletStartPoint.getPosition());
		bullet->setRotation(getRotation());
		bullet->setAngle(getRotation());
		bullet->unRelease();
		bullet->setTexture(TextureLoader::getTexture("Bullet"));
		bullet->lateInit();

		GameObjectHandler::addGameObject(BULLET, bullet);
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
