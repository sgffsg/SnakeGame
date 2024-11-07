#include "Cell.h"

Cell::Cell()
{
	this->x = -1;
	this->y = -1;
	this->cellContent = CellContent::NONE;
}

Cell::Cell(int x, int y)
{
	this->x = x;
	this->y = y;
	this->cellContent = CellContent::EMPTY;
}

Cell::Cell(int x, int y, CellContent cellContent)
{
	this->x = x;
	this->y = y;
	this->cellContent = cellContent;
}

bool Cell::OnBoard()
{
	return (x >= 0 && x < this->config.BOARD_ROW_SIZE) &&
			(y >= 0 && y < this->config.BOARD_COLUMN_SIZE);
}

CellContent Cell::GetCellContent()
{
	return this->cellContent;
}

void Cell::ChangeCellContent(CellContent newCellContent)
{
	this->cellContent = newCellContent;
}

const char Cell::GetCellOutSymbol()
{
    switch (cellContent)
    {
		case CellContent::EMPTY:
			return config.CELL_OUT;

		case CellContent::BORDER:
			return config.BORDER_OUT;

		case CellContent::SNAKE_HEAD:
			return config.SNAKE_HEAD_OUT;

		case CellContent::SNAKE_TAIL:
			return config.SNAKE_TAIL_OUT;

		case CellContent::APPLE:
			return config.APPLE_OUT;

		default:
			return config.SPACE_OUT;
    }
}


bool Cell::IsEmpty()
{
	return this->cellContent == CellContent::EMPTY;
}

bool Cell::IsContainsApple()
{
	return this->cellContent == CellContent::APPLE;
}

bool Cell::IsContainsSnake()
{
	return this->cellContent == CellContent::SNAKE_HEAD || 
			 this->cellContent == CellContent::SNAKE_TAIL;
}
