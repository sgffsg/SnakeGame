#include <iostream>
#include <vector>
#include <Board.h>
#include <SnakeEngine.h>




int main()
{
    setlocale(LC_ALL, "russian");
    int seed = time(NULL);
    srand(seed);

    SnakeEngine snakeEngine;

    snakeEngine.StartGame();
    //system("pause");
    snakeEngine.EndGame();
}
