#pragma once
#include "Config.h"
#include "CellContent.h"

class Cell
{
	private:
		int x;
		int y;
		CellContent cellContent;

		Config config;
	public:
		

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

