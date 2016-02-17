#include "GameWindow.h"

GameWindow::GameWindow()
{
	setup("Window", sf::Vector2u(800, 600));
}

GameWindow::GameWindow(const std::string& title, const sf::Vector2u& size)
{
	setup(title, size);
}

GameWindow::~GameWindow()
{
	destroy();
}

void GameWindow::setup(const std::string& title, const sf::Vector2u& size)
{
	_windowTitle = title;
	_windowSize = size;
	_isFullscreen = false;
	_isDone = false;
	create();
}

void GameWindow::create()
{
	auto style = (_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	_window.create({ _windowSize.x, _windowSize.y, 32 }, _windowTitle, style);
}

void GameWindow::destroy()
{
	_window.close();
}

void GameWindow::update()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			toggleFullscreen();
		}
	}
}

void GameWindow::toggleFullscreen()
{
	_isFullscreen = !_isFullscreen;
	destroy();
	create();
}

void GameWindow::beginDraw()
{
	_window.clear(sf::Color::Black);
}

void GameWindow::endDraw()
{
	_window.display();
}

bool GameWindow::isDone()
{
	return _isDone;
}

bool GameWindow::isFullscreen()
{
	return _isFullscreen;
}

sf::Vector2u GameWindow::getWindowSize()
{
	return _windowSize;
}

void GameWindow::draw(sf::Drawable& drawable)
{
	_window.draw(drawable);
}
