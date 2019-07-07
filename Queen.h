#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen();
	~Queen();
	//inherited constructor
	Queen(float x, float y, float boardXsize, float boardYsize, int type);

	//move queen
	bool move(float x, float y);
	//print queen
	void printString() override;
};

