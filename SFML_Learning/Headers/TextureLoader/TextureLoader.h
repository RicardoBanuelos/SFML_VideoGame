#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class TextureLoader {
public:
	TextureLoader();
	~TextureLoader();

	bool loadTexture(const std::string& textureName, const std::string& texturePath);
	sf::Texture& getTexture(const std::string& textureName);
private:
	std::unordered_map<std::string, sf::Texture> mTexturesMap;
};