#include "SnakeEngine.h"


void SnakeEngine::StartGame()
{
	this->board.Init();
	this->snake.snakeBody = this->board.CreateSnake();
	this->apple = this->board.CreateApple();
	
	this->config.isPlayerWin = false;
	this->config.gameIsStarted = true;
	
	std::cout << "Игра Запущена" << std::endl;
	this->Update();
}

void SnakeEngine::InputHandler()
{
	if (_kbhit())
	{
		char input = _getch();

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

		Sleep(config.SNAKE_SPEED);
				
		this->board.PrintBoard();
		this->InputHandler();
		this->snake.Move();
		this->board.GetNeighborCell(this->snake.snakeBody[0].x, this->snake.snakeBody[0].y, this->snake.GetMoveDirection());
		
		std::cout << "\nИдет игра" << std::endl;
		std::cout << "MoveDirection: " << (int)snake.GetMoveDirection() << std::endl;
		std::cout << "Нажмите q - для выхода, r - для перезапуска." << std::endl;
	}

	this->EndGame();
}

void SnakeEngine::EndGame()
{
	if (config.isPlayerWin)
		std::cout << "Победа!" << std::endl;
	else
		std::cout << "Поражение." << std::endl;
	this->config.gameIsStarted = false;
	this->config.isPlayerWin = false;
}
