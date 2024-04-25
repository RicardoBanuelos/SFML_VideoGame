#include "TextureLoader/TextureLoader.h"

std::unordered_map<std::string, sf::Texture> TextureLoader::mTexturesMap;

bool TextureLoader::loadTexture(const std::string& textureName, const std::string& texturePath)
{
	sf::Texture texture;

	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	mTexturesMap[textureName] = texture;
	return true;
}

sf::Texture& TextureLoader::getTexture(const std::string& textureName)
{
	return mTexturesMap[textureName];
}