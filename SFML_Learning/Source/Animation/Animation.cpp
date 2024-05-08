#include "Animation/Animation.h"
#include "GameMath/GameMath.h"

#include <iostream>

Animation::Animation(sf::Sprite& sprite, int frameCount, float frameDuration, int startingRow, int width, int height)
	:	mSprite(sprite),
		mFrameCount(frameCount),
		mFrameDuration(frameDuration),
		mCurrentFrame(0),
		mDuration(0.0f),
		mRow(startingRow),
		mWidth(width),
		mHeight(height)
{}

void Animation::update(float deltaTime)
{
	mDuration += deltaTime;

	if (mDuration < mFrameDuration) return;
	if (mCurrentFrame >= mFrameCount) mCurrentFrame = 0;

	mDuration = 0.0f;

	sf::IntRect textureRect(mCurrentFrame * mWidth, mRow * mHeight, mWidth, mHeight);
	mSprite.setTextureRect(textureRect);

	++mCurrentFrame;
}

void Animation::setRow(int row)
{
	mRow = row;
	mCurrentFrame = 0;
}

void Animation::setFrameCount(int frameCount)
{
	mFrameCount = frameCount;
}

void Animation::setFrameDuration(float frameDuration)
{
	mFrameDuration = frameDuration;
}