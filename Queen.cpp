#include "Queen.h"
#include <cmath>
#include <iostream>
using namespace std;

//constructor
Queen::Queen()
{
}

//destructor
Queen::~Queen()
{
}

//inherit piece constructor
Queen::Queen(float x, float y, float boardXsize, float boardYsize, int type): Piece(x,y,boardXsize, boardYsize, type)
{
}


//move Queen
bool Queen::move(float x, float y)
{
	if (moveDiag(x, y) == true) {
		//move has been done
		return true;
	}
	else if (moveUDLR(x, y) == true){
		//move has been done
		return true;
	}
	//move not done therefore return false
	//commented out to clean up output. comment back in to see proof that invalid moves are being cancelled
	//cout << "attempted invalid move on queen to" << x << "," << y << "\n";
	return false;
}

//print Queen
void Queen::printString()
{
	cout << "Queen at position " << x << "," << y << "\n";
}