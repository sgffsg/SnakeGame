#include "SnakeEngine.h"
#include <iostream>

SnakeEngine::SnakeEngine()
{
}

void SnakeEngine::StartGame()
{
	std::cout << "Игра Запущена" << std::endl;
	this->board.Init();
}

void SnakeEngine::EndGame()
{
	std::cout << "Игра Завершена" << std::endl;
}

void SnakeEngine::Draw()
{
}
