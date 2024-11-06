#pragma once
class Config
{
private:

public:
#pragma region GAME
	const int GAMEFIELD_ROW_SIZE = 16;
	const int GAMEFIELD_COLUMN_SIZE = 16;
	const int FRAMES_PER_SECOND = 60;
#pragma endregion

#pragma region BOARD PRESET
	const int BOARD_ROW_SIZE = GAMEFIELD_ROW_SIZE;
	const int BOARD_COLUMN_SIZE = GAMEFIELD_COLUMN_SIZE;
	const int BOARD_SIZE = GAMEFIELD_ROW_SIZE * GAMEFIELD_COLUMN_SIZE;
#pragma endregion

#pragma region SNAKE PRESET
	const int MIN_SNAKE_SIZE = 2;
	const int SNAKE_SPEED = 400;
#pragma endregion

#pragma region INPUT PRESET
	// Game
	const char GAME_start = 's';
	const char GAME_PAUSE = 'p';
	const char GAME_RESUME = 'r';
	const char GAME_EXIT = 'q';

	// Local Player
	const char UP_DIRECTION = 'w';
	const char DOWN_DIRECTION = 's';
	const char RIGHT_DIRECTION = 'd';
	const char LEFT_DIRECTION = 'a';

	// 1ST Player
	const char P1_UP_DIRECTION = 'w';
	const char P1_DOWN_DIRECTION = 's';
	const char P1_RIGHT_DIRECTION = 'd';
	const char P1_LEFT_DIRECTION = 'a';

	// 2ST Player
	const char P2_UP_DIRECTION = 65;
	const char P2_DOWN_DIRECTION = 66;
	const char P2_RIGHT_DIRECTION = 67;
	const char P2_LEFT_DIRECTION = 68;
#pragma endregion

#pragma region OUTPUT PRESET
	const char CELL_OUT = '-';
	const char SPACE_OUT = ' ';
	const char APPLE_OUT = '@';
	const char BORDER_OUT = '!';
	const char SNAKE_HEAD_OUT = 'O';
	const char SNAKE_BODY_OUT = 'o';
	const char SNAKE_TAIL_OUT = '&';
#pragma endregion		
};