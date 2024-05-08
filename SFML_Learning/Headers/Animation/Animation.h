#pragma once

#include <SFML/Graphics.hpp>
 
class Animation {
public:
	Animation(sf::Sprite& sprite, int frameCount, float frameDuration, int width, int height);
	void update(float deltaTime);

private:
	sf::Sprite& mSprite;
	int mFrameCount;
	float mFrameDuration;
	int mCurrentFrame;
	float mDuration;
	int mWidth;
	int mHeight;
};