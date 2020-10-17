#include "Game.hpp"


int main()
{
	Game* game = new Game(600, 600, "FUCK YOU!", 30);

	game->loop();

	return 0;
}