#pragma once
#include "Cell.h"

struct Apple
{
	private:
		
	public:
		Cell* appleCell;

		Apple();
		Apple(Cell appleCell);
		Cell GetAppleCell();
};

