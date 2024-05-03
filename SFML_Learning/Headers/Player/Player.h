#pragma once

#include "GameObject/GameObject.h"

#include "Weapons.h"
#include "Bullet/Bullet.h"

#include <vector>

class Player : public GameObject {
public:
	Player(sf::Vector2f position, const sf::Texture& texture);
	virtual ~Player();

	virtual void init() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
private:
	void checkKeyInput(float deltaTime);
	void rotate();
	void shoot(float deltaTime);

	sf::Vector2f getWeaponOffsetPosition(WeaponID weapon);
	sf::RectangleShape mBulletStartPoint;
};