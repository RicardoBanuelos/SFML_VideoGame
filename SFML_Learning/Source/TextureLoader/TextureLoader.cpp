#include "TextureLoader/TextureLoader.h"
#include "TextureLoader/TextureStrings.h"

#include <iostream>

bool TextureLoader::mTexturesReady = false;
std::unordered_map<std::string, sf::Texture> TextureLoader::mTexturesMap;

bool TextureLoader::loadAllTextures()
{
	for (auto& [name, path] : TextureStrings::texturePaths)
	{
		if (!loadTexture(name, path))
		{
			std::cout << "Failed loading textures." << std::endl;
			return false;
		}
	}

	std::cout << "Succesfully loaded all textures." << std::endl;
	return true;
}

 void TextureLoader::dropAllTextures()
{	
	 mTexturesMap.clear();
}

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