#pragma once
#include <string>
class Config
{
	private:
	
	public:
	#pragma region GAME
		bool gameIsStarted = false;
		bool isPlayerWin = false;
		bool isDifficultyEnabled = false;
	#pragma endregion

	#pragma region BOARD_PRESET
		const int BOARD_ROW_COUNT = 16;
		const int BOARD_COLUMN_COUNT = 16;
	#pragma endregion

	#pragma region SNAKE_PRESET
		const int MIN_SNAKE_SIZE = 2;
		const int SNAKE_SPEED = 400;
	#pragma endregion
		
	#pragma region OUTPUT_PRESET
		const char CELL_OUT = '-';
		const char SPACE_OUT = ' ';
		const char APPLE_OUT = '@';
		const char BORDER_OUT = '!';
		const char SNAKE_HEAD_OUT = 'O';
		const char SNAKE_TAIL_OUT = 'o';
	#pragma endregion		
};