#pragma once
#include <deque>

#include "Cell.h"
#include "MoveDirection.h"

class Snake
{
	private:
		std::deque<Cell> snakeBody;

		MoveDirection moveDirection;
		MoveDirection lastMoveDirection;

		void Grow(Cell newCell);

		void CheckCollision();
		bool CheckAppleCollision();
		bool CheckBorderCollision();
		bool CheckOwnCollision();
	public:
		Snake();

		MoveDirection GetMoveDirection();

		void Move();
		void Eat();
};

