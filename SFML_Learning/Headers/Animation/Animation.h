#pragma once

#include <SFML/Graphics.hpp>
 
class Animation {
public:
	Animation(sf::Sprite& sprite, int frameCount, float frameDuration, int startingRow, int width, int height);
	void update(float deltaTime);
	void setRow(int row);
	void setFrameCount(int frameCount);
	void setFrameDuration(float frameDuration);

private:
	sf::Sprite& mSprite;
	int mFrameCount;
	float mFrameDuration;
	int mCurrentFrame;
	float mDuration;
	int mRow;
	int mWidth;
	int mHeight;
};