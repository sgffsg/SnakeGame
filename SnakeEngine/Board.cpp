#include "Board.h"


#pragma region INIT
void Board::Init()
{
	this->cells = std::vector <std::vector<Cell>>();
	InitField();		
}

void Board::InitField()
{
	for (int x = 0; x < config.BOARD_ROW_COUNT; x++)
	{
		std::vector<Cell> cellRow;

		for (int y = 0; y < config.BOARD_COLUMN_COUNT; y++)
		{
			if (x == 0 || x == config.BOARD_ROW_COUNT - 1 || y == 0 || y == config.BOARD_COLUMN_COUNT - 1)
				cellRow.push_back(Cell(x, y, CellContent::BORDER));
			else
				cellRow.push_back(Cell(x, y));
		}

		cells.push_back(cellRow);
	}
}

Cell Board::CreateApple()
{
	while (true)
	{
		int randRow = rand() % (config.BOARD_ROW_COUNT - 1);
		int randCol = rand() % (config.BOARD_COLUMN_COUNT - 1);

		if (this->cells[randRow].at(randCol).OnBoard() && this->cells[randRow].at(randCol).IsEmpty())
		{
			this->cells[randRow].at(randCol).ChangeCellContent(CellContent::APPLE);
			return this->cells[randRow].at(randCol);
		}
	}
	return this->cells[0].at(0);
}

std::deque<Cell> Board::CreateSnake()
{
	std::deque<Cell> snakeBody = std::deque<Cell>();

	int snakeHeadX = config.BOARD_ROW_COUNT / 2 - 1;
	int snakeHeadY = config.BOARD_COLUMN_COUNT / 2 - 1;

	this->ChangeCellContent(snakeHeadX, snakeHeadY, CellContent::SNAKE_HEAD);
	this->ChangeCellContent(snakeHeadX + 1, snakeHeadY, CellContent::SNAKE_TAIL);

	snakeBody.push_front(this->GetCell(snakeHeadX, snakeHeadY));
	snakeBody.push_back(this->GetCell(snakeHeadX + 1, snakeHeadY));

	return snakeBody;
}
#pragma endregion

#pragma region GET
Cell Board::GetCell(int row, int col)
{
	if (this->cells[row].at(col).OnBoard())
		return this->cells[row].at(col);

	return Cell();
}

Cell Board::GetLeftNeighbor(int row, int column)
{
	if (column == 0)
		return Cell();

	return GetCell(row, column - 1);
}

Cell Board::GetRightNeighbor(int row, int column)
{
	if (column >= config.BOARD_COLUMN_COUNT - 1)
		return Cell();

	return GetCell(row, column + 1);
}

Cell Board::GetTopNeighbor(int row, int column)
{
	if (row == 0)
		return Cell();

	return GetCell(row - 1, column);
}

Cell Board::GetBottomNeighbor(int row, int column)
{
	if (row >= config.BOARD_ROW_COUNT - 1)
		return Cell();

	return GetCell(row + 1, column);
}

Cell Board::GetNeighborCell(int row, int column, MoveDirection moveDirection)
{
	if (moveDirection == MoveDirection::LEFT)
		return GetLeftNeighbor(row, column);
	if (moveDirection == MoveDirection::UP)
		return GetTopNeighbor(row, column);
	if (moveDirection == MoveDirection::RIGHT)
		return GetRightNeighbor(row, column);
	if (moveDirection == MoveDirection::DOWN)
		return GetBottomNeighbor(row, column);
	return Cell();
}
#pragma endregion

bool Board::IsWin()
{
	for (int x = 0; x < cells.size(); x++)
		for (int y = 0; y < cells[x].size(); y++)
			if (cells[x].at(y).IsEmpty())
				return false;
	return true;
}

void Board::ChangeCellContent(int row, int col, CellContent newCellContent)
{
	if (this->cells[row].at(col).OnBoard())
		cells[row].at(col).ChangeCellContent(newCellContent);
}

void Board::PrintBoard()
{
	system("cls");

	std::for_each(cells.begin(), cells.end(), [](const std::vector<Cell>& row) {
		std::cout << "  \n";
		for_each(row.begin(), row.end(), [](Cell element) {
			std::cout << "  " << element.GetCellOutSymbol() << "  ";
		});
		std::cout << "\n";
	});
}

void Board::UpdateBoard(std::deque<Cell> snake, Apple apple)
{
	this->cells = std::vector<std::vector<Cell>>();
	InitField();
	for (auto& snakeElement : snake)
	{
		this->ChangeCellContent(snakeElement.x, snakeElement.y, snakeElement.GetCellContent());
	}

	this->ChangeCellContent(apple.x, apple.y, CellContent::APPLE);
}

