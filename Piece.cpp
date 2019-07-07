#include "Piece.h"
#include <iostream>
using namespace std;

//constructors
Piece::Piece()
{
}

Piece::Piece(float x, float y, float boardXsize, float boardYsize, int type)
{
	//set board size
	this->boardX = boardXsize;
	this->boardY = boardYsize;

	//initialise score
	this->score = 0;

	//check valid type
	//queen = 0, bishop = 1, rook = 2
	if (type == 0 || type == 1 || type == 2) {
		//set type
		setType(type);
	}
	else {
		//invalid type
		throw "invalid type! needs to be either 0, 1 or 2";
	}
	//check valid x. Must be on board
	if (x >= 0 && x <= getBoardX())
	{
		//valid therefore set
		setX(x);
	}
	else {
		//invalid throw error
		throw "invalid X position! needs to be within the confines of the board";
	}
	//check valid y. Must be on board
	if (y >= 0 && y <= getBoardY())
	{
		//valid therefore set
		setY(y);
	}
	else {
		//invalid throw error
		throw "invalid Y position! needs to be within the confines of the board";
	}
}

//Destructor
Piece::~Piece()
{
}
//printString
void Piece::printString()
{
	//overload in other methods
}

bool  Piece::move(float x, float y)
{
	//overload in other methods
	return true;
}

bool Piece::onBoard(float x, float y)
{
	//check x value acceptable
	if (x <= getBoardX() && x >= 0) {
		//ceheck y val acceptable
		if (y <= getBoardY() && y >= 0) {
			return true;
		}
	}
	//otherwise return false
	return false;
}

//movement
//move up down left or right (Bishop and queen)
bool Piece::moveUDLR(float x, float y)
{
	//check the move is on the board
	if (onBoard(x, y) == false) {
		return false;
	}

	//check if move valid
	//check if moving up/down
	//done by subtracting current x and y from new x andy y to calclulate the amount moved on x and y
	if ((abs(getX() - x) != 0) && (abs(getY() - y) == 0)) {
		//do move
		setX(x);
		return true;
	}
	//check if moving left/right
	else if ((abs(getX() - x) == 0) && (abs(getY() - y) != 0)) {
		//do move
		setY(y);
		return true;
	}
	else {
		return false;
	}
}
//move diagonally (rook and queen)
bool Piece::moveDiag(float x, float y) {

	//check the move is on the board
	if (onBoard(x, y) == false) {
		return false;
	}

	//check diagonal move by subtracting current x and y from new x and yto calclulate the amount moved on x and y
	if (abs(getX() - x) == abs(getY() -y)) {
		//do move
		setX(x);
		setY(y);
		return true;
	}
	else {
		//not applicable therefore return false
		return false;
	}
}

//getMethods
float Piece::getX()
{
	return x;
}
float Piece::getY()
{
	return y;
}
float Piece::getBoardY()
{
	return boardY;
}
float Piece::getRadius()
{
	return radius;
}
int Piece::getType()
{
	return type;
}
int Piece::getScore()
{
	return this->score;
}
float Piece::getBoardX()
{
	return boardX;
}

//setMethods
void Piece::setX(float x)
{
	this->x = x;
}
void Piece::setY(float y)
{
	this->y = y;
}

void Piece::setType(int type)
{
	this->type = type;
}
//increase score by 1
void Piece::incrementScore()
{
	this->score = getScore() + 1;
}



