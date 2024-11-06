#include "Board.h"

Board::Board()
{
	this->cells = std::vector <std::vector<Cell>>();
}


#pragma region INIT
	void Board::Init()
	{
		InitCells();
		InitSnake();
		InitApple();
		PrintBoard();
	}

	void Board::InitCells()
	{
		for (int x = 0; x < this->config.BOARD_ROW_SIZE; x++)
		{
			std::vector<Cell> cellRow;

			for (int y = 0; y < this->config.BOARD_COLUMN_SIZE; y++)
			{
				if (x == 0 || x == config.BOARD_ROW_SIZE - 1 || y == 0 || y == config.BOARD_COLUMN_SIZE - 1)
					cellRow.push_back(Cell(x, y, CellContent::BORDER));
				else
					cellRow.push_back(Cell(x, y));
			}

			cells.push_back(cellRow);
		}
	}

	void Board::InitSnake()
	{
		int startPosRow = config.BOARD_ROW_SIZE / 2 - 1;
		int startPosCol = config.BOARD_COLUMN_SIZE / 2 - 1;

		this->cells[startPosRow].at(startPosCol).ChangeCellContent(CellContent::SNAKE_HEAD);
		this->cells[startPosRow + 1].at(startPosCol).ChangeCellContent(CellContent::SNAKE_BODY);
		this->cells[startPosRow + 2].at(startPosCol).ChangeCellContent(CellContent::SNAKE_TAIL);
	}

	void Board::InitApple()
	{
		while (true)
		{
			int randRow = rand() % (this->config.BOARD_ROW_SIZE - 1);
			int randCol = rand() % (this->config.BOARD_COLUMN_SIZE - 1);

			if (this->cells[randRow].at(randCol).OnBoard() && this->cells[randRow].at(randCol).IsEmpty())
			{
				this->cells[randRow].at(randCol).ChangeCellContent(CellContent::APPLE);
				this->apple = Apple(this->cells[randRow].at(randCol));
				break;
			}
		}
	}
#pragma endregion

	

	Cell Board::GetCell(int row, int col)
{
	if (this->cells[row].at(col).OnBoard())
		return this->cells[row].at(col);

	return Cell();
}

std::vector<std::vector<Cell>> Board::GetCells()
{
	return this->cells;
}

Cell Board::GetAppleCell()
{
	for (int x = 0; x < cells.size(); x++)
		for (int y = 0; y < cells[x].size(); y++)
			if (cells[x].at(y).IsContainsApple())
				return cells[x].at(y);
	return Cell(1, 1, CellContent::APPLE);
}

void Board::PrintBoard()
{
	for (int x = 0; x < cells.size(); x++)
	{
		std::vector<Cell> cellRow = cells[x];
		std::cout << config.SPACE_OUT << config.SPACE_OUT << std::endl;

		for (int y = 0; y < cells[x].size(); y++)
		{
			std::cout << config.SPACE_OUT << config.SPACE_OUT;
			std::cout << GetCell(x, y).GetCellOutSymbol();
			std::cout << config.SPACE_OUT << config.SPACE_OUT;
		}
		std::cout << std::endl;
	}
}
