#pragma once
#include "conio.h"
#include <iostream>
#include "windows.h"

#include "Board.h"
#include "Apple.h"
#include "Snake.h"
#include "MoveDirection.h"
#include "Config.h"

class SnakeEngine
{
	
	private:
		Apple apple = Apple();
		Snake snake = Snake();
		Board board = Board();
		Config config = Config();

		void InputHandler();
	public:
		void StartGame();
		void EndGame();

		void Update();
};

