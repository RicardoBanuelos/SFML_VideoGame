#pragma once

#include "GameObject/GameObject.h"
#include "Collisions/ICollidable.h"

#include "Animation/Animation.h"

class Player;

class Zombie : public GameObject
{
public:
	Zombie();
	Zombie(sf::Vector2f position);
	virtual ~Zombie();

	virtual void init() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void processCollision(ICollidable* other) override;

	void takeDamage(float damage);
	float damage();

	void setPlayer(Player* player);
private:
	enum ZombieState {
		ZS_WALKING,
		ZS_ATTACKING,
		ZS_DEAD,
		ZS_SIZE
	};

	void handlePlayerCollision(float deltaTime);
	void handleZombieCollision(float deltaTime);

	void playWalkingAnimation();
	void playPunchAnimation();

	ZombieState mPreviousState;
	ZombieState mState;

	Player* mPlayer;

	float mAttackDelay;
	float mHealth;
	float mDamage;

	Animation* mAnimations;

	static const float OVERLAPPING_THRESHOLD;
	static const float OVERLAPPING_FACTOR;
};