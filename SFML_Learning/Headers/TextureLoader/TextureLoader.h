#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

#include "TextureLoader/TextureData.h"

class TextureLoader {
public:
	TextureLoader() = delete;

	static bool loadAllTextures();
	static void dropAllTextures();

	static sf::Texture& getTexture(TextureData::TextureID id);

private:
	static bool loadTexture(TextureData::TextureID id, const std::string& texturePath);

	static std::unordered_map<TextureData::TextureID, sf::Texture> mTexturesMap;
};