#include <Game/Game.h>

int main()
{
	std::srand(std::time(0));

	Game* game;
	game->run();

	return 0;
}