#include "TextureLoader/TextureLoader.h"
#include "TextureLoader/TextureData.h"

#include <iostream>

std::unordered_map<TextureData::TextureID, sf::Texture> TextureLoader::mTexturesMap;

bool TextureLoader::loadAllTextures()
{
	for (auto& [ID, path] : TextureData::texturePaths)
	{
		if (!loadTexture(ID, path))
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

bool TextureLoader::loadTexture(TextureData::TextureID id, const std::string& texturePath)
{
	sf::Texture texture;

	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	mTexturesMap[id] = texture;
	return true;
}

sf::Texture& TextureLoader::getTexture(TextureData::TextureID id)
{
	return mTexturesMap[id];
}