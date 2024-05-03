#pragma once

#include "GameObject/GameObject.h"
class Player;

class Zombie : public GameObject 
{
public:
	Zombie();
	Zombie(sf::Vector2f position, const sf::Texture& texture);
	Zombie(sf::Vector2f position, const sf::Texture& texture, Player* player);
	virtual ~Zombie();

	virtual void init() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;

	void setPlayer(Player* player);
private:
	Player* mPlayer;
};