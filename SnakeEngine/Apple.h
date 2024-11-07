#pragma once
#include "Cell.h"

class Apple
{
	private:
		Cell* appleCell;
	public:
		

		Apple();
		Apple(Cell appleCell);
		Cell GetAppleCell();
};

