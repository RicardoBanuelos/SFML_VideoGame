#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

namespace GameMath {
	inline const float PI = 3.14159265358979323846;

	inline sf::Vector2f normalize(const sf::Vector2f& vector)
	{
		float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);

		float normalizedX = vector.x / magnitude;
		float normalizedY = vector.y / magnitude;

		return sf::Vector2f(normalizedX, normalizedY);
	}

	inline float angleToRadians(float angle)
	{
		return angle * (PI / 180);
	}
}