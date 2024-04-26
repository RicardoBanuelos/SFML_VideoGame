#pragma once

#include "GameObject/GameObject.h"

class Zombie : public GameObject 
{
public:
	Zombie();
	Zombie(sf::Vector2f position, const sf::Texture& texture);
	virtual ~Zombie();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
private:
};