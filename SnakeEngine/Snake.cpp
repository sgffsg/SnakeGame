#include "Snake.h"

void Snake::Grow(Cell newCell)
{
}

void Snake::CheckCollision()
{
	CheckBorderCollision();
	CheckAppleCollision();
	CheckOwnCollision();
}

bool Snake::CheckAppleCollision()
{
	return false;
}

bool Snake::CheckBorderCollision()
{
	return false;
}

bool Snake::CheckOwnCollision()
{
	return false;
}

Snake::Snake()
{
	this->moveDirection = MoveDirection::UP;
	this->lastMoveDirection = MoveDirection::NONE;
}

MoveDirection Snake::GetMoveDirection()
{
	return this->moveDirection;
}

void Snake::Move()
{
	CheckCollision();
}

void Snake::Eat()
{
	Grow(Cell());
}
