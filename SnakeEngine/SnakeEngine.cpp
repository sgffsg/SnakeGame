#include "SnakeEngine.h"

void SnakeEngine::StartGame()
{
	this->board.Init();
	this->snake.moveDirection = MoveDirection::UP;

	this->snake.snakeBody = this->board.CreateSnake();
	this->snake.ChangeSneakHeadPosition();

	Cell appleCell = this->board.CreateApple();
	this->apple = Apple(appleCell.x, appleCell.y);

	this->difficultModificator = config.SNAKE_SPEED - snake.snakeBody.size() * 25;
	this->config.isPlayerWin = false;
	this->config.gameIsStarted = true;

	std::cout << "Игра Запущена\n";
	this->Update();
}

void SnakeEngine::EndGame()
{
	if (config.isPlayerWin)
		std::cout << "Победа!\n";
	else
		std::cout << "Поражение.\n";

	this->config.gameIsStarted = false;
	this->config.isPlayerWin = false;
}

void SnakeEngine::Update()
{
	while (config.gameIsStarted)
	{
		if (board.IsWin())
		{
			this->config.isPlayerWin = true;
			this->EndGame();
		}

		if (config.isDifficultyEnabled)
			Sleep(difficultModificator);
		else
			Sleep(config.SNAKE_SPEED);

		this->InputHandler();
		this->CheckCollision();
		this->board.UpdateBoard(snake.snakeBody, apple);
		this->board.PrintBoard();

		std::cout << "\nИдет игра\n";
		std::cout << "Нажмите q - для выхода, r - для перезапуска.\n";
	}

	this->EndGame();
}

void SnakeEngine::InputHandler()
{
	if (_kbhit())
	{
		int input = _getch();
		if (input == 0 || input == 224)
			InputArrowHandler();
		else
			InputKeyboardHandler(input);
	}
}

void SnakeEngine::InputArrowHandler()
{
	switch (_getch()) 
	{
		case 72:
			this->snake.SetMoveDirection(MoveDirection::UP);
			break;
		case 75:
			this->snake.SetMoveDirection(MoveDirection::LEFT);
			break;
		case 77:
			this->snake.SetMoveDirection(MoveDirection::RIGHT);
			break;
		case 80:
			this->snake.SetMoveDirection(MoveDirection::DOWN);
			break;
	}
}


void SnakeEngine::InputKeyboardHandler(char input)
{
	switch (input)
	{
		case 'w':
			this->snake.SetMoveDirection(MoveDirection::UP);
			break;
		case 'a':
			this->snake.SetMoveDirection(MoveDirection::LEFT);
			break;
		case 's':
			this->snake.SetMoveDirection(MoveDirection::DOWN);
			break;
		case 'd':
			this->snake.SetMoveDirection(MoveDirection::RIGHT);
			break;
		case 'q':
			config.gameIsStarted = false;
			break;
		case 'r':
			this->StartGame();
			break;
		default:
			break;
	}
}

void SnakeEngine::CheckCollision()
{
	Cell neighborCell = board.GetNeighborCell(this->snake.snakeHeadRowPosition, this->snake.snakeHeadColumnPosition, this->snake.moveDirection);

	if (neighborCell.IsBorder() || neighborCell.IsContainsSnake())
		this->EndGame();

	if (neighborCell.IsContainsApple())
	{
		this->snake.Grow(neighborCell);
		Cell cell = this->board.CreateApple();
		this->apple = Apple(cell.x, cell.y);
		IncreaseDifficult();
	}
		
	if (neighborCell.IsEmpty())
		this->snake.Move(neighborCell);
}

void SnakeEngine::IncreaseDifficult()
{
	if (difficultModificator > 25)
		this->difficultModificator = config.SNAKE_SPEED - snake.snakeBody.size() * 25;
}
