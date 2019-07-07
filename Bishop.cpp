#include "Bishop.h"
#include <cmath>
#include <iostream>
using namespace std;


Bishop::Bishop()
{
}


Bishop::~Bishop()
{
}

//inherit piece constructor
Bishop::Bishop(float x, float y, float boardXsize, float boardYsize, int type) : Piece(x, y, boardXsize, boardYsize, type)
{
}

//move bishop
bool Bishop::move(float x, float y)
{
	if (moveDiag(x, y) == true) {
		//move done, return true
		return true;
	}
	//commented out to clean up output. comment back in to see proof that invalid moves are being cancelled
	//cout << "attempted invalid move on bishop to" << x << "," << y << "\n";
	return false;
}

//print bishop
void Bishop::printString()
{
	cout << "Bishop at position " << x << "," << y << "\n";
}

