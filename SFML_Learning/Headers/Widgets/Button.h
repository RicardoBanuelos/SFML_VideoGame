#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

class Button {
public:
	Button();
	Button(sf::Font& font, const std::string& text);
	~Button();

	void setFont(sf::Font& font);
	void setText(const std::string& text);
	void setTextSize(int size);
	void setTextColor(sf::Color color);
	void setOnHoverColor(sf::Color color);

	void setPosition(int x, int y);
	void setSize();
	void setSize(int width, int height);

	sf::Vector2f getSize();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	bool isClicked();

	void setOnClickFunction(std::function<void()> function);

private:
	void alignText();

	bool mouseIsOverButton(const sf::Vector2f& mousePosition);

	void onHover();
	void onUnHover();

	sf::Text mText;
	sf::Color mTextColor;
	sf::Color mTextHoverColor;

	sf::Vector2f mPosition;
	sf::Vector2f mSize;

	sf::RectangleShape mRectangle;

	std::function<void()> mOnClickFunction;
	bool mClicked;
};
