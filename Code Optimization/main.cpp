#include "Game.h"

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const float DELAY_TIME = 1000.0f / FPS;

	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("Cord Optimization", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
	}
	else {
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	Uint32 frameStart, frameTime;

	while (TheGame::Instance()->running())
	{
		frameStart = SDL_GetTicks();
		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}

	std::cout << "game closing...\n";
	TheGame::Instance()->clean();
	return 0;
}