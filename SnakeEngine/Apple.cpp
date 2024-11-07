#include "Apple.h"

Apple::Apple()
{
	
}

Apple::Apple(Cell appleCell)
{
	this->appleCell = &appleCell;
	
}

Cell Apple::GetAppleCell()
{
	return *this->appleCell;
}

//Cell Apple::Create(Cell appleCell)
//{
//	this->appleCell = &appleCell;
//	this->appleCell->ChangeCellContent(CellContent::APPLE);
//	return *this->appleCell;
//}
