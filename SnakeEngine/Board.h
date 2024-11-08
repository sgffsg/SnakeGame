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
#include "Apple.h"
#include "Snake.h"
#include "Config.h"
#include "CellContent.h"
#include "MoveDirection.h"



struct Board
{
	private:	
		Config config = Config();
		std::vector<std::vector<Cell>> cells;
		
		void InitField();
		
		Cell GetLeftNeighbor(int row, int column);
		Cell GetTopNeighbor(int row, int column);
		Cell GetRightNeighbor(int row, int column);
		Cell GetBottomNeighbor(int row, int column);

	public:
		Board();

		void Init();
		bool IsWin();
		void PrintBoard();

		Cell CreateApple();
		std::deque<Cell> CreateSnake();

		Cell GetCell(int row, int col);
		std::vector<std::vector<Cell>> GetAllCells();
		Cell GetNeighborCell(int row, int col, MoveDirection moveDirection);

		void ChangeCellContent(int row, int col, CellContent cellContent);
		
};

