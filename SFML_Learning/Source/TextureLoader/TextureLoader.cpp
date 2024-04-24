#include "TextureLoader/TextureLoader.h"

TextureLoader::TextureLoader() {}

TextureLoader::~TextureLoader() {}

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
	sf::Texture texture;
	if (mTexturesMap.count(textureName) == 0) return texture;

	return mTexturesMap[textureName];
}
