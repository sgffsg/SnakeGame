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
		Board board = Board();
		Apple apple = Apple(-1, -1);
		Snake snake = Snake();
		Config config;

		int difficultModificator;

		void Update();

		void InputHandler();
		void InputArrowHandler();
		void InputKeyboardHandler(char input);

		void CheckCollision();
		void IncreaseDifficult();
		
	public:
		void StartGame();
		void EndGame();

		
};

