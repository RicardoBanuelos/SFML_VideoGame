#pragma once

#include "GameObject/GameObject.h"

class Character : public GameObject {
public:
	Character(sf::Vector2f position, sf::Vector2f size, sf::Texture& texture);
	~Character();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void move(sf::Vector2f direction);

private:
};