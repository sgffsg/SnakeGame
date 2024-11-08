#pragma once
#include <deque>

#include "Cell.h"
#include "Board.h"
#include "MoveDirection.h"

struct Snake
{
	private:
		
		MoveDirection moveDirection;
		MoveDirection lastMoveDirection;
	public:
		std::deque<Cell> snakeBody;
		Snake();
		void Init();
		void Move();
		
		MoveDirection GetMoveDirection();
		void SetMoveDirection(MoveDirection moveDirection);	
};

