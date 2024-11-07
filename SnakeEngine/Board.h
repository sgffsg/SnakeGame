#pragma once
#include <vector>
#include <iostream>
#include <deque>
//#include <iterator>
//#include <random>
//#include <conio.h>
//#include "windows.h"
//#include <iomanip>

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
		
		void InitField();
		void InitSnake();
		

	public:
		Board();

		void Init();
		bool IsWin();
		void PrintBoard();

		Cell CreateApple();
		std::deque<Cell> CreateSnake();

		Cell GetCell(int row, int col);
		std::vector<std::vector<Cell>> GetAllCells();
		void ChangeCellContent(int row, int col, CellContent cellContent);
		
};

