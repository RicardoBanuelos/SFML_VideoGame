#pragma once

#include <SFML/Graphics.hpp>

class Camera {
public:
	Camera(float widht, float height);
	~Camera();

	void move(float offsetX, float offsetY);
	void zoom(float factor);
	void setCenter(float x, float y);
	void moveTowards(float targetX, float targetY, float speed);
	sf::View getView() const;

private:
	sf::View mView;
};