#include "Rook.h"
#include <cmath>
#include <iostream>
using namespace std;
//constructor
Rook::Rook()
{
}

//inherited constructor
Rook::Rook(float x, float y, float boardXsize, float boardYsize, int type) :Piece(x, y, boardXsize, boardYsize, type)
{
}

//destructor
Rook::~Rook()
{
}

//move rook
bool Rook::move(float x, float y)
{
	if (moveUDLR(x,y) == true) {
		//move has been done
		return true;
	}
	//commented out to clean up output. comment back in to see proof that invalid moves are being cancelled
	//cout << "attempted invalid move on rook to" << x << "," << y << "\n";
	return false;
}

//print rook
void Rook::printString()
{
	cout << "Rook at position " << x << "," << y << "\n";
}
