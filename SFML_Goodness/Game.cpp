#include "Game.h"

Game::Game() : _gameWindow("Chapter 2", sf::Vector2u(800, 600))
{
	if (!_penguinTexture.loadFromFile("blue-monster.png"))
		_gameWindow.~GameWindow();

	_penguin.setTexture(_penguinTexture);
	sf::Vector2u size = _penguinTexture.getSize();
	_penguin.setOrigin(size.x / 2, size.y / 2);

	_penguin.setPosition(400, 300);
	_velocity = sf::Vector2i(400, 400);
}

Game::~Game() {}

GameWindow* Game::getWindow()
{
	return &_gameWindow;
}
void Game::handleInput() {}

void Game::update()
{
	_gameWindow.update();
	movePenguin();
}

void Game::movePenguin()
{
	sf::Vector2u windSize = _gameWindow.getWindowSize();
	sf::Vector2u textureSize = _penguinTexture.getSize();

	if ((_penguin.getPosition().x + _penguin.getOrigin().x > windSize.x && _velocity.x > 0) ||
		_penguin.getPosition().x - _penguin.getOrigin().x < 0 && _velocity.x < 0)
	{
		_velocity.x *= -1;
		int r, g, b;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		_penguin.setColor(sf::Color(r, g, b, 255));
	}

	if ((_penguin.getPosition().y + _penguin.getOrigin().y > windSize.y && _velocity.y > 0) ||
		_penguin.getPosition().y - _penguin.getOrigin().y < 0 && _velocity.y < 0)
	{
		_velocity.y *= -1;
		int r, g, b;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		_penguin.setColor(sf::Color(r, g, b, 255));
	}

	float elapsed = _elapsed.asSeconds();

	_penguin.setPosition(
		_penguin.getPosition().x + (_velocity.x * elapsed), 
		_penguin.getPosition().y + (_velocity.y * elapsed));
}

void Game::render()
{
	_gameWindow.beginDraw();
	_gameWindow.draw(_penguin);
	_gameWindow.endDraw();
}

sf::Time Game::getElapsed()
{
	return _elapsed;
}

void Game::restartClock()
{
	_elapsed = _clock.restart();
}
