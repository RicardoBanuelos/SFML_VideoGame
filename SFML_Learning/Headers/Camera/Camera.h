#pragma once

#include <SFML/Graphics.hpp>

class Camera {
public:
	Camera(float width, float height);
	~Camera();

	void follow(sf::Vector2f playerPos);
	sf::View getView() const;

private:
	void move(float offsetX, float offsetY);
	void zoom(float factor);
	void setCenter(float x, float y);
	void moveTowards(float targetX, float targetY, float speed);

	sf::View mView;
};