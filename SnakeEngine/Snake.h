#pragma once
#include <deque>

#include "Cell.h"
#include "Board.h"
#include "Config.h"
#include "MoveDirection.h"

class Snake
{
	private:
		

		Config config;
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

