#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class TextureLoader {
public:
	TextureLoader() = delete;

	static bool loadAllTextures();
	static void dropAllTextures();

	static bool loadTexture(const std::string& textureName, const std::string& texturePath);
	static sf::Texture& getTexture(const std::string& textureName);

private:
	static bool mTexturesReady;
	static std::unordered_map<std::string, sf::Texture> mTexturesMap;
};