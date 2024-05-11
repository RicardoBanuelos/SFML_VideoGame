#include "Widgets/Button.h"
#include "MousePosition/MousePosition.h"

#include <iostream>

Button::Button()
	:	mClicked(false)
{
}

Button::Button(sf::Font& font, const std::string& text)
	:	Button()
{
	mText.setFont(font);
	mText.setString(text);

#ifdef TESTING
	mRectangle.setFillColor(sf::Color::Transparent);
	mRectangle.setOutlineColor(sf::Color::Red);
	mRectangle.setOutlineThickness(1.0f);
#endif
}

Button::~Button()
{

}

void Button::setFont(sf::Font& font)
{
	mText.setFont(font);
}

void Button::setText(const std::string& text)
{
	mText.setString(text);
}

void Button::setTextSize(int size)
{
	mText.setCharacterSize(size);

	alignText();
}

void Button::setTextColor(sf::Color color)
{
	mTextColor = color;
	mText.setFillColor(mTextColor);
}

void Button::setOnHoverColor(sf::Color color)
{
	mTextHoverColor = color;
}

void Button::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;

	mRectangle.setPosition(mPosition);
	mText.setPosition(mPosition);

	alignText();
}

void Button::setSize()
{
	int width = mText.getLocalBounds().width;
	int height = mText.getLocalBounds().height;

	mSize.x = width;
	mSize.y = height;

	mRectangle.setSize(mSize);

	alignText();
}

void Button::setSize(int width, int height)
{
	mSize.x = width;
	mSize.y = height;

	mRectangle.setSize(mSize);

	alignText();
}

sf::Vector2f Button::getSize()
{
	return sf::Vector2f(mText.getLocalBounds().width, mText.getLocalBounds().height);
}

void Button::update(float deltaTime)
{
	sf::Vector2f mousePosition = MousePosition::get();

	if (mouseIsOverButton(mousePosition))
	{
		onHover();
		if (!mClicked && isClicked())
		{
			if (mOnClickFunction)
			{
				mClicked = true;
				mOnClickFunction();
			}
		}

		if (!isClicked())
		{
			mClicked = false;
		}
	}
	else
	{
		mClicked = false;
		onUnHover();
	}
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(mText);
	window.draw(mRectangle);
}

bool Button::isClicked()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

void Button::setOnClickFunction(std::function<void()> function)
{
	mOnClickFunction = function;
}

void Button::alignText()
{
	const float left = mText.getLocalBounds().left;
	const float top = mText.getLocalBounds().top;

	mText.setOrigin(left, top);
}

bool Button::mouseIsOverButton(const sf::Vector2f& mousePosition)
{
	return mRectangle.getGlobalBounds().contains(mousePosition);
}

void Button::onHover()
{
	mText.setFillColor(mTextHoverColor);
}

void Button::onUnHover()
{
	mText.setFillColor(mTextColor);
}