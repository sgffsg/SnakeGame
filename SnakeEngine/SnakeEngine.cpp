#include "SnakeEngine.h"
#include <iostream>

SnakeEngine::SnakeEngine()
{
}

void SnakeEngine::StartGame()
{
	std::cout << "���� ��������" << std::endl;
	this->board.Init();
}

void SnakeEngine::EndGame()
{
	std::cout << "���� ���������" << std::endl;
}

void SnakeEngine::Draw()
{
}
