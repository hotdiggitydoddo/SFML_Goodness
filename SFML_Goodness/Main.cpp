#include <SFML\Graphics.hpp>

#include "Game.h"

int main(int argc, char** argv)
{
	Game game;

	while (!game.getWindow()->isDone())
	{
		game.handleInput();
		game.update();
		game.render();
		game.restartClock();
	}

	return 0;
}