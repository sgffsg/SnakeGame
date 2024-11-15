#pragma once
#include <deque>
#include <algorithm>

#include "Cell.h"
#include "Board.h"
#include "Config.h"
#include "MoveDirection.h"

struct Snake
{
	private:
		Config config;
		
	public:
		Snake();
		std::deque<Cell> snakeBody;
		int snakeHeadRowPosition;
		int snakeHeadColumnPosition;

		MoveDirection moveDirection;
		MoveDirection lastMoveDirection;

		void ChangeSneakHeadPosition();
		
		void Move(Cell cell);
		void Grow(Cell cell);

		MoveDirection GetMoveDirection();
		void SetMoveDirection(MoveDirection moveDirection);	
};

