#pragma once
#include "Board.h"

class SnakeEngine
{
	
	private:
		Board board = Board();

	public:
		SnakeEngine();
		
		void StartGame();
		void EndGame();

		void Draw();
};

