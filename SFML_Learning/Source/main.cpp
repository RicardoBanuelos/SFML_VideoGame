#include "TextureLoader/TextureLoader.h"
#include "Game/Game.h"


int main()
{
	std::srand(std::time(0));

	if (!TextureLoader::loadAllTextures()) return -1;

	Game game;
	game.run();

	return 0;
}