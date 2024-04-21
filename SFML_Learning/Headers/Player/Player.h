#pragma once

#include "Character/Character.h"

class Player : public Character {
public:
	Player(sf::Vector2f position, sf::Vector2f size, sf::Texture& texture);
	~Player();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void move(sf::Vector2f direction) override;
private:

};