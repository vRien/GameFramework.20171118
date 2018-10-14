#include "Game.h"

Game* g_game = 0;

int main(int argc, char* argv[])
{
	g_game = new Game();
	g_game->init("Chapter 1", 128, 82, 640, 480, false);

	while (g_game->running())
	{
		g_game->render();
		g_game->update();
	}
	g_game->clean();
	return 0;
}