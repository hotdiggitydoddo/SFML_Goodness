#pragma once
#include<SFML\Graphics.hpp>

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction
{
	None, Up, Down, Left, Right
};

class Snake
{
public:
	Snake(int blockSize);
	~Snake();

	// Helper methods.
	void setDirection(Direction dir);
	Direction getDirection();
	int getSpeed();
	sf::Vector2i getPosition();
	int getLives();
	int getScore();
	void increaseScore();
	bool hasLost();

	void lose();  // Handles losing.
	void toggleLost();

	void extend();  // Grow the snake.
	void reset();  // Reset to starting position

	void move();  // Movement
	void tick();  // Update
	void cut(int segments); 
	void render(sf::RenderWindow& window);

private:
	void checkCollision();

	SnakeContainer _snakeBody;  // segment vector
	int _size;  // size of graphics
	Direction _dir;
	int _speed;
	int _lives;
	int _score;
	bool _lost;
	sf::RectangleShape _bodyRect; // shape used in rendering.
};