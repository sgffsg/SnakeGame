#pragma once
#include "Config.h"
#include "CellContent.h"

class Cell
{
	private:
		Config config;
		CellContent cellContent;
	public:
		int x;
		int y;

		Cell();
		Cell(int x, int y);
		Cell(int x, int y, CellContent cellContent);
		bool OnBoard();

		const char GetCellOutSymbol();
		CellContent GetCellContent();
		
		void ChangeCellContent(CellContent newCellContent);

		bool IsEmpty();
		bool IsContainsApple();
		bool IsContainsSnake();
};

