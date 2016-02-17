#pragma once
#include "GameWindow.h"
#include <SFML\Graphics.hpp>
#include <stdlib.h>

class Game
{
public:
	Game();
	~Game();

	void handleInput();
	void update();
	void render();

	sf::Time getElapsed();
	void restartClock();

	GameWindow* getWindow();

private:
	void movePenguin();
	GameWindow _gameWindow;

	sf::Texture _penguinTexture;
	sf::Vector2i _velocity;
	sf::Sprite _penguin;

	sf::Clock _clock;
	sf::Time _elapsed;
};
