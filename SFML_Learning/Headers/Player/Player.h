#pragma once

#include "GameObject/GameObject.h"

#include "Animation/Animation.h"
#include "Weapons.h"

class Player : public GameObject
{
public:
	Player(sf::Vector2f position);
	virtual ~Player();

	virtual void init() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void processCollision(ICollidable* other) override;

	void takeDamage(float damage);
	float health();
private:
	enum PlayerState {
		PS_WALKING,
		PS_SHOOTING,
	};

	void checkKeyInput(float deltaTime);
	void rotate();
	void shoot(float deltaTime);

	void playWalkingAnimation();
	void playShootingAnimation();

	PlayerState mState;

	Animation* mAnimations;
	sf::Vector2f getWeaponOffsetPosition(WeaponID weapon);
	sf::RectangleShape mBulletStartPoint;

	float mHealth;
};