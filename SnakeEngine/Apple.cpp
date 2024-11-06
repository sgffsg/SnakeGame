#include "Apple.h"

Apple::Apple()
{
	
}

Apple::Apple(Cell appleCell)
{
	this->appleCell = &appleCell;
}

bool Apple::CheckCollision()
{
	return false;
}
