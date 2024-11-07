#include "Snake.h"
#include <conio.h>
#include <iostream>
#include <string>



Snake::Snake()
{
	this->moveDirection = MoveDirection::NONE;
	this->lastMoveDirection = MoveDirection::NONE;
}

void Snake::Init()
{
	int startPosRow = config.BOARD_ROW_SIZE / 2 - 1;
	int startPosCol = config.BOARD_COLUMN_SIZE / 2 - 1;
}

void Snake::Move()
{
	this->lastMoveDirection = this->moveDirection;
}

MoveDirection Snake::GetMoveDirection()
{
	return this->moveDirection;
}

void Snake::SetMoveDirection(MoveDirection moveDirection)
{
	switch (lastMoveDirection)
	{
		case MoveDirection::LEFT:
			if (moveDirection != MoveDirection::RIGHT)
				this->moveDirection = moveDirection;
			break;
		case MoveDirection::UP:
			if (moveDirection != MoveDirection::DOWN)
				this->moveDirection = moveDirection;
			break;
		case MoveDirection::RIGHT:
			if (moveDirection != MoveDirection::LEFT)
				this->moveDirection = moveDirection;
			break;
		case MoveDirection::DOWN:
			if (moveDirection != MoveDirection::UP)
				this->moveDirection = moveDirection;
			break;
		default:
			this->moveDirection = moveDirection;
			break;
	}
	
}