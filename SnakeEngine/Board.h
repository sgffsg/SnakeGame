#pragma once
#include <vector>
#include <iterator>
#include <random>
#include <conio.h>
#include "windows.h"
#include <iostream>
#include "Cell.h"
#include "CellContent.h"
#include "Apple.h"
#include "Snake.h"
#include "Config.h"

class Board
{
	private:
		Config config;
		std::vector<std::vector<Cell>> cells;
		Apple apple;
		Snake snake;

		void InitCells();
		void InitSnake();
		void InitApple();

	public:
		Board();

		Cell GetCell(int row, int col);
		Cell GetAppleCell();
		std::vector<std::vector<Cell>> GetCells();

		void Init();
		void PrintBoard();
};

