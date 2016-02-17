#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class GameWindow
{
public:
	GameWindow();
	GameWindow(const std::string& title, const sf::Vector2u& size);
	~GameWindow();

	void beginDraw(); // Clear the window.
	void endDraw(); // Display the changes.

	void update();

	bool isDone();
	bool isFullscreen();
	void toggleFullscreen();
	void draw(sf::Drawable& l_drawable);

	sf::Vector2u getWindowSize();

private:
	void setup(const std::string& title, const sf::Vector2u& size);
	void destroy();
	void create();

	sf::RenderWindow _window;
	sf::Vector2u _windowSize;
	std::string _windowTitle;
	bool _isDone;
	bool _isFullscreen;

};