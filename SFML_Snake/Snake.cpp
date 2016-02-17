#include "Snake.h"

Snake::Snake(int blockSize)
{
	_size = blockSize;
	_bodyRect.setSize(sf::Vector2f(_size - 1, _size - 1));
	reset();
}

Snake::~Snake() {}

void Snake::setDirection(Direction dir)
{
	_dir = dir;
}

Direction Snake::getDirection()
{
	return _dir;
}

int Snake::getSpeed()
{
	return _speed;
}

sf::Vector2i Snake::getPosition()
{
	return (!_snakeBody.empty() ? _snakeBody.front().position : sf::Vector2i(1, 1));
}

int Snake::getLives()
{
	return _lives;
}

int Snake::getScore()
{
	return _score;
}

void Snake::increaseScore()
{
	_score += 10;
}

bool Snake::hasLost()
{
	return _lost;
}

void Snake::lose()
{
	_lost = true;
}

void Snake::toggleLost()
{
	_lost = !_lost;
}

void Snake::extend()
{
	if (_snakeBody.empty())
		return;

	SnakeSegment& tail_head = _snakeBody[_snakeBody.size() - 1];

	if (_snakeBody.size() > 1)
	{
		SnakeSegment& tail_bone = _snakeBody[_snakeBody.size() - 2];

		if (tail_head.position.x == tail_bone.position.x)
		{
			if (tail_head.position.y > tail_bone.position.y)
				_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
			else
				_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		}
		else if (tail_head.position.y == tail_bone.position.y)
		{
			if (tail_head.position.x > tail_bone.position.x) 
				_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
			else
				_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
		else
		{
			if (_dir == Direction::Up)
				_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
			else if (_dir == Direction::Down)
				_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
			else if (_dir == Direction::Right)
				_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
			else if (_dir == Direction::Left)
				_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
		}
	}


}

void Snake::reset()
{
	_snakeBody.clear();
	_snakeBody.push_back(SnakeSegment(5, 7));
	_snakeBody.push_back(SnakeSegment(5, 6));
	_snakeBody.push_back(SnakeSegment(5, 5));

	setDirection(Direction::None);

	_speed = 15;
	_lives = 3;
	_score = 0;
	_lost = false;
}
