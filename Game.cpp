#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//number of each piece
const int numQ = 1;
const int numB = 1;
const int numR = 1;

//size of board
const float boardX = 10;
const float boardY = 10;

//max amount of moves
const int maxMoves = 100;

//pieces left on board
int piecesLeft;

//Type constants
//queen = 0, bishop = 1, rook = 2 KEEP THESE THE SAME for declaring the type value
const int queenType = 0;
const int bishopType = 1;
const int rookType = 2;

//create random integer
float randomMove(float limit) {
	return (rand() % (int)limit);
}

//generate methods:
//generate a queen
vector<Piece*> genQ(vector<Piece*> pieces) {
	Queen* q = new Queen(randomMove(boardX), randomMove(boardY), boardX, boardY, queenType);
	pieces.push_back(q);
	cout << "Queen generated: \n";
	q->printString();
	return pieces;
}
//generate a bishop
vector<Piece*> genB(vector<Piece*> pieces) {
	Bishop* b = new Bishop(randomMove(boardX), randomMove(boardY), boardX, boardY, bishopType);
	pieces.push_back(b);
	cout << "Bishop generated: \n";
	b->printString();
	return pieces;
}
//generate a rook
vector<Piece*> genR(vector<Piece*> pieces) {
	Rook* r = new Rook(randomMove(boardX), randomMove(boardY), boardX, boardY, rookType);
	pieces.push_back(r);
	cout << "Rook generated: \n";
	r->printString();
	return pieces;
}


//detect collisions 

//circle square collision
//only call from collision detection which will order it the correct way
bool cirlceSquareCol(Piece* square, Piece* circle) {
	//piece lhs must be circle
	//peice rhs must be square

	//	_|_|_  1,2,3   numbered each square to simplify explination
	//	_|_|_  4,5,6
	//	 | |   7,8,9

	//calculate the diff in x and y
	float diffX = abs(square->getX() - circle->getX());
	float diffY = abs(square->getY() - circle->getY());
	float totalRad = square->getRadius() + circle->getRadius();

	//if the circle is within squares 2,4,5,6 or 8 as shown above (corner not nearest point)
	if ((diffX <= totalRad) && (diffY <= square->getRadius())) {
		//collides
		return true;
	}
	if((diffX <= square->getRadius()) && (diffY <= totalRad)) {
		//collides
		return true;
	}

	//get each corner value
	float cornerX[4];
	float cornerY[4];
	//top right
	cornerX[0] = square->getX() + square->getRadius();
	cornerY[0] = square->getX() + square->getRadius();
	//top left
	cornerX[1] = square->getX() - square->getRadius();
	cornerY[1] = square->getX() + square->getRadius();
	//bottom left
	cornerX[2] = square->getX() - square->getRadius();
	cornerY[2] = square->getX() - square->getRadius();
	//bottom right
	cornerX[3] = square->getX() + square->getRadius();
	cornerY[3] = square->getX() - square->getRadius();

	//for each corner see if distance to center of circle is <=1 circle radius. if so touching therefore collision
	for (int i=0; i < 4; i++) {
		//calc diff from corner to circle squared
		float cornerDifX = powf(abs(cornerX[i] - circle->getX()), 2);
		float cornerDifY = powf(abs(cornerY[i] - circle->getY()), 2);
		//if a^2 + b^2 <= c^2 must be colliding
		if (cornerDifX + cornerDifY <= powf(circle->getRadius(), 2)) {
			return true;
		}
	}

	//must not be touching if reached here as all possibilities checked
	return false;
}


//method to detect all collisions
bool collisionDetection(Piece* lhs, Piece* rhs) {
	//find out which collision type it could be. like circle-cirlce/ square-circle/ square-square
	//circle circle collision
	if ((lhs->getType() == 0 || lhs->getType() == 1) && (rhs->getType() == 0 || rhs->getType() == 1)) {
		//the value between the two midpoints of two circles should be the radius + radius or less if touching
		//if touching im classing as collision. This could be changed to only if one was over the other if i changed >= to <
		float diffX = powf((lhs->getX() - rhs->getX()), 2);
		float diffY = powf((rhs->getY() - lhs->getY()), 2);
		//difference between midpoints a^2 = b^2 + c^2 to calc hypotenuse
		if (powf(lhs->getRadius() + rhs->getRadius(),2) >= diffX + diffY) {
			//collide
			return true;
		}
		//dont collide
		return false;
	}
	//circle square
	if ((lhs->getType() == 2) && (rhs->getType() == 0 || rhs->getType() == 1)) {
		//do the method for circle square
		return cirlceSquareCol(lhs,rhs);
	}
	//square circle
	if ((lhs->getType() == 0 || lhs->getType() == 1) && (rhs->getType() == 2)) {
		//do circle square method with variable order reversed
		return cirlceSquareCol(rhs,lhs);
	}
	//square square
	if ((lhs->getType() == 2) && (rhs->getType() == 2)) {
		//collide when diff x and diff y from center of both circles are within lhs+rhs radius of each other
		float diffX = abs(lhs->getX() - rhs->getX());
		float diffY = abs(lhs->getY() - rhs->getY());
		float totalRad = lhs->getRadius() + rhs->getRadius();
		if ((diffX <= totalRad) && (diffY <= totalRad)){
			//collide
			return true;
		}
		//doesnt collide
		return false;
	}

	//should never reach this point as every collision should have been detected but just incase throw error
	throw "error, cant detect collision for the two pieces passed";
}


//run the game
int main() {

	//create a seed for rand
	srand((unsigned)time(NULL));

	//create a vector to store each piece
	piecesLeft = numQ + numB + numR;
	vector<Piece*> pieces(0);
	//generate pieces for the game
	for (int i = 0; i < numQ; i++) {
		pieces = genQ(pieces);
	}
	for (int i = 0; i < numB; i++) {
		pieces = genB(pieces);
	}
	for (int i = 0; i < numR; i++) {
		pieces = genR(pieces);
	}

	//do the moves of the game
	for (int i = 0; i < maxMoves; i++) {
		//for each move, each peice gets one turn
		for (int a = 0; a < piecesLeft; a++) {
			
			//generate a random move
			float x = randomMove(boardX);
			float y = randomMove(boardY);
			//try doing move
			while (pieces[a]->move(x, y) == false) {
				//try doing move again because was invalid
				x = randomMove(boardX);
				y = randomMove(boardY);
			}
			
			//only will exit loop once found a valid move
			//print out to prove that the move happened
			cout << "piece " << a << " ";
			pieces[a]->printString();

			//check for collisions on all pieces left
			for (int b = 0; b < piecesLeft; b++) {
				//make sure not to compare the peice just moved to its self
				if (a != b) {
					//check if colliding
					bool colDetected = collisionDetection(pieces[a], pieces[b]);
					if (colDetected == true) {
						//delete rhs and incrememnt lhs score
						pieces[a]->incrementScore();
						//system("Pause");
						cout << "collision detected, score incremented! score is now: " << pieces[a]->getScore() << "\n";
						cout << "deleted piece " << b << " which was at position " << pieces[b]->getX() << ", " << pieces[b]->getY() << "\n";
						pieces.erase(pieces.begin() + b);
						//decrement pieces left
						piecesLeft = piecesLeft - 1;
						//if the piece deleted was then everything in the vector will have moved one down in the order
						//therefore decrement b and a by one
						b = b - 1;
						a = a - 1;
		
					}
				}
			}
		}
		if (piecesLeft == 1) {
			//only one piece left therefore end game
			cout << "Last remaining piece is ";
			pieces[0]->printString();
			cout << "With a score of: " << pieces[0]->getScore() << "\n";
			break;
		}
	}

	system("Pause");
}
