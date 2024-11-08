#pragma once
#include "CellContent.h"
#include "Config.h"



struct Cell
{
	private:
		
		CellContent cellContent;
		Config config = Config();
	public:
		int x;
		int y;

		Cell();
		Cell(int x, int y);
		Cell(int x, int y, CellContent cellContent);

		CellContent GetCellContent();
		void ChangeCellContent(CellContent newCellContent);
		const char GetCellOutSymbol();

		bool OnBoard();
		bool IsEmpty();
		bool IsContainsApple();
		bool IsContainsSnake();
};

