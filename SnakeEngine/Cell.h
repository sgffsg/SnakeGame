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

		const char GetCellOutSymbol();

		CellContent GetCellContent();
		void ChangeCellContent(CellContent newCellContent);
		
		bool OnBoard();
		bool IsEmpty();
		bool IsBorder();
		bool IsContainsApple();
		bool IsContainsSnake();
};

