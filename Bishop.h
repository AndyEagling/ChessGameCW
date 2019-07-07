#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop();
	~Bishop();
	//inherited constructor
	Bishop(float x, float y, float boardXsize, float boardYsize, int type);

	//move bishop
	bool move(float x, float y);
	//print bishop
	void printString() override;
};

