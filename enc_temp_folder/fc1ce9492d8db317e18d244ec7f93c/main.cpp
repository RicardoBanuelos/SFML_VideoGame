#include <Game/Game.h>

int main()
{
	std::srand(std::time(0));

	Game* game = new Game();
	game->run();

	delete game;

	return 0;
}