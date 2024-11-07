#include "Board.h"

Board::Board()
{
	
}


#pragma region INIT
	void Board::Init()
	{
		this->cells = std::vector <std::vector<Cell>>();
		InitField();
		//InitSnake();
		
	}

	void Board::InitField()
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
		
	}

	Cell Board::CreateApple()
	{
		while (true)
		{
			int randRow = rand() % (this->config.BOARD_ROW_SIZE - 1);
			int randCol = rand() % (this->config.BOARD_COLUMN_SIZE - 1);

			if (this->cells[randRow].at(randCol).OnBoard() && this->cells[randRow].at(randCol).IsEmpty())
			{
				this->cells[randRow].at(randCol).ChangeCellContent(CellContent::APPLE);
				return cells[randRow].at(randCol);
			}
		}
		return Cell();
	}

	std::deque<Cell> Board::CreateSnake()
	{
		std::deque<Cell> snakeBody;
		int startPosRow = config.BOARD_ROW_SIZE / 2 - 1;
		int startPosCol = config.BOARD_COLUMN_SIZE / 2 - 1;
		this->cells[startPosRow].at(startPosCol).ChangeCellContent(CellContent::SNAKE_HEAD);
		this->cells[startPosRow + 1].at(startPosCol).ChangeCellContent(CellContent::SNAKE_TAIL);

		snakeBody.push_front(this->cells[startPosRow].at(startPosCol));
		snakeBody.push_back(this->cells[startPosRow + 1].at(startPosCol));
		
		return snakeBody;
	}
#pragma endregion

Cell Board::GetCell(int row, int col)
{
	if (this->cells[row].at(col).OnBoard())
		return this->cells[row].at(col);

	return Cell();
}

std::vector<std::vector<Cell>> Board::GetAllCells()
{
	return this->cells;
}

void Board::ChangeCellContent(int row, int col, CellContent newCellContent)
{
	if (this->cells[row].at(col).OnBoard())
		cells[row].at(col).ChangeCellContent(newCellContent);
}


bool Board::IsWin()
{
	for (int x = 0; x < cells.size(); x++)
		for (int y = 0; y < cells[x].size(); y++)
			if (cells[x].at(y).IsEmpty())
				return false;
	return true;
}

void Board::PrintBoard()
{
	system("cls");
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

