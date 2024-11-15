#include "Snake.h"

Snake::Snake()//Board &board)
{
	this->snakeHeadRowPosition = -1;
	this->snakeHeadColumnPosition = -1;
	this->snakeBody = std::deque<Cell>();
	this->moveDirection = MoveDirection::UP;
	this->lastMoveDirection = MoveDirection::NONE;
}

void Snake::ChangeSneakHeadPosition()
{
	this->snakeHeadRowPosition = snakeBody[0].x;
	this->snakeHeadColumnPosition = snakeBody[0].y;
}


void Snake::Move(Cell cell)
{
	this->lastMoveDirection = this->moveDirection;
	this->snakeBody[0].ChangeCellContent(CellContent::SNAKE_TAIL);
	cell.ChangeCellContent(CellContent::SNAKE_HEAD);
	this->snakeBody.push_front(cell);
	this->snakeBody.pop_back();
	ChangeSneakHeadPosition();
}

void Snake::Grow(Cell cell)
{
	std::for_each(snakeBody.begin(), snakeBody.end(), [](Cell element) {
			element.ChangeCellContent(CellContent::SNAKE_TAIL);
		});
	cell.ChangeCellContent(CellContent::SNAKE_HEAD);
	this->snakeBody.push_front(cell);
	ChangeSneakHeadPosition();
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