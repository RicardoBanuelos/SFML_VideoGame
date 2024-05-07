#pragma once

#include "GameObject/GameObject.h"
#include "Collisions/ICollidable.h"

class Player;

class Zombie : public GameObject
{
public:
	Zombie();
	Zombie(sf::Vector2f position);
	Zombie(sf::Vector2f position, const sf::Texture& texture);
	Zombie(sf::Vector2f position, const sf::Texture& texture, Player* player);
	virtual ~Zombie();

	virtual void init() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void processCollision(ICollidable* other) override;

	void takeDamage(float damage);
	float damage();

	void lateInit();
	void setPlayer(Player* player);
private:
	Player* mPlayer;

	float mAttackDelay;
	float mHealth;
	float mDamage;
};