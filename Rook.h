#pragma once
#include "Piece.h"
#include <string>

class Rook :
	public Piece
{
public:
	Rook();
	//inherited constructor
	Rook(float x, float y, float boardXsize, float boardYsize, int type);
	~Rook();

	//move rook
	bool move(float x, float y);
	//print rook
	void printString() override;
};

