#pragma once
class Piece
{
public:
	//constructors
	Piece();
	Piece(float x, float y, float boardX, float boardY, int type);

	//desctructor
	~Piece();

	//toString
	virtual void printString();

	//move
	virtual bool move(float x, float y);

	//check if a value is on the board
	bool onBoard(float x, float y);

	//get values
	float getX();
	float getY();
	float getBoardX();
	float getBoardY();
	float getRadius();
	int getType();
	int getScore();

	//set values
	void setX(float x);
	void setY(float y);
	void setType(int type);
	void incrementScore();
	//no set methods for board size as static and will define them in the constructor


protected:
	//move methods
	//protected so that the piece in game doesnt have accses to them 
	//therefore has to use the correct move method for the object

	//move up down left or right
	bool moveUDLR(float x, float y);
	//move diagonally
	bool moveDiag(float x, float y);


	//variables

	//position of peice
	float x;
	float y;

	//type
	int type;

	//radius
	const float radius = 1;

	//score
	int score;

	//board size
	//wanted to make static/const so cant be overridden but gave an unresolved symbol error.
	//therefore i have just taken care not to change the board size anywhere except the constant in game.cpp
	float boardX;
	float boardY;
};