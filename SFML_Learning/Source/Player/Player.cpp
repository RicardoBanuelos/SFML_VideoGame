#include "Player/Player.h"

#include <iostream>
#include <math.h>

#include "TextureLoader/TextureLoader.h"
#include "MousePosition/MousePosition.h"
#include "GameMath/GameMath.h"

#include "ObjectPool/ObjectPoolHandler.h"
#include "GameObject/GameObjectHandler.h"
#include "GameObject/GameObjectBuilder.h"

#include "Bullet/Bullet.h"

Player::Player(sf::Vector2f position)
	:	GameObject(position),
		mHealth(100.0f),
		mBulletCount(12)
{
	init();
}

Player::~Player() 
{}

void Player::init()
{
	mState = PS_WALKING;
	mID = PLAYER;
	mSpeed = 1000.0f;

	setTexture(TextureLoader::getTexture(TextureData::TID_PLAYER));
	setTextureRect(sf::IntRect(0, 0, 255, 215));
	initHitBox();
	alignCenter();

	mAnimations = new Animation(*this, 1, 100.0f, 0, 255, 215);
}

void Player::update(float deltaTime)
{
	checkKeyInput(deltaTime);
	rotate();

	mAnimations->update(deltaTime);
	mBulletStartPoint.setPosition(getWeaponOffsetPosition(HANDGUN));

	if (mState == PS_RELOADING)
	{
		handleReloading(deltaTime);
	}
	else 
	{
		shoot(deltaTime);
	}

	GameObject::update(deltaTime);
}

void Player::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
}

void Player::processCollision(ICollidable* other)
{
	std::cout << "Player Collision" << std::endl;
}

void Player::takeDamage(float damage)
{
	mHealth = GameMath::clamp<float>(0, 100, mHealth - damage);
}

float Player::health()
{
	return mHealth;
}

void Player::checkKeyInput(float deltaTime)
{
	sf::Vector2f direction;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && mBulletCount < 12)
	{
		mState = PS_RELOADING;
		playReloadingAnimation();
	}
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

void Player::handleReloading(float deltaTime)
{
	mReloadingTimer += deltaTime;
	if (mReloadingTimer >= 1.0f)
	{
		mState = PS_WALKING;
		mReloadingTimer = 0.0;
		mBulletCount = 12;
		std::cout << "Walking Animation" << std::endl;
		playWalkingAnimation();
	}
}

void Player::shoot(float deltaTime)
{
	static float accumTime = 0;
	accumTime += deltaTime;

	if (mState == PS_SHOOTING && accumTime >= 0.25f)
	{
		mState = PS_WALKING;
		playWalkingAnimation();
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && accumTime >= 0.25f)
	{
		accumTime = 0; 
		--mBulletCount;

		mState = PS_SHOOTING;
		playShootingAnimation();

		Bullet* bullet = GameObjectBuilder::buildBullet(mBulletStartPoint.getPosition(), getRotation());
		GameObjectHandler::addGameObject(BULLET, bullet);
	}

	if (mBulletCount == 0)
	{
		mState = PS_RELOADING;
		playReloadingAnimation();
	}
}

void Player::playWalkingAnimation()
{
	mAnimations->setRow(0);
	mAnimations->setFrameCount(1);
	mAnimations->setFrameDuration(0.1f);
}

void Player::playShootingAnimation()
{
	mAnimations->setRow(2);
	mAnimations->setFrameCount(3);
	mAnimations->setFrameDuration(0.083f);
}

void Player::playReloadingAnimation()
{
	mAnimations->setRow(1);
	mAnimations->setFrameCount(15);
	mAnimations->setFrameDuration(0.0667f);
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
