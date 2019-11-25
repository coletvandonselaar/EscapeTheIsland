#pragma once
#include<vector>
#include<iostream>
#include "Location.h"
using namespace std;
class GameBoard
{
public:
	const char UNVISTED_MARK = '?';
	const char CURRENT_LOCATION = 'O';
	const char VISITED_LOCATION = 'X';
	const int AMOUNT_OF_GEMS = 4;
	void printGameBoard();
	vector<vector<char> >* getGameBoard();
	void generateMapDetails();
	void moveLocation(string);
	void getPlayerLocationXY(int &, int &);

private:
	vector<vector<char> > gameBoard{ {UNVISTED_MARK,UNVISTED_MARK, UNVISTED_MARK, UNVISTED_MARK},
									{UNVISTED_MARK,UNVISTED_MARK, UNVISTED_MARK, UNVISTED_MARK},
									{UNVISTED_MARK,UNVISTED_MARK, UNVISTED_MARK, UNVISTED_MARK},
									{UNVISTED_MARK,UNVISTED_MARK, UNVISTED_MARK, UNVISTED_MARK} };
	
	vector<vector<Location>> roomDetails;

	void setOldLocation(int, int);
};

