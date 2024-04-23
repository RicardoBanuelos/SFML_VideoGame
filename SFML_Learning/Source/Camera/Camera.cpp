#include "Camera/Camera.h"

Camera::Camera(float width, float height)
{
	mView.setSize(width, height);
	mView.setCenter(width / 2, height / 2);
}

Camera::~Camera() {}

void Camera::move(float offsetX, float offsetY)
{
	mView.move(offsetX, offsetY);
}

void Camera::zoom(float factor)
{
	mView.zoom(factor);
}

void Camera::setCenter(float x, float y)
{
	mView.setCenter(x, y);
}

void Camera::moveTowards(float targetX, float targetY, float speed)
{
	float dx = targetX - mView.getCenter().x;
	float dy = targetY - mView.getCenter().y;
	float distance = std::sqrt(dx * dx + dy * dy);

	if (distance > speed) {
		mView.move(dx * speed / distance, dy * speed / distance);
	}
}

sf::View Camera::getView() const
{
	return mView;
}