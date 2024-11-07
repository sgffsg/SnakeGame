#include <SnakeEngine.h>


int main()
{
    int seed = time(NULL);
    srand(seed);

    setlocale(LC_ALL, "russian");

    SnakeEngine snakeEngine;
    snakeEngine.StartGame();
}
