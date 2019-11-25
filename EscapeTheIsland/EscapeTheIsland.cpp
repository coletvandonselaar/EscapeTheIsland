// EscapeTheIsland.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ctvandonselaar@dmacc.edu 11/24/2019
//Shows how the map will work, the movement will work, as well as different classes I will need for the final game
	//Will create a vector of items and will randomly select an item inside GameBoard.generateMapDetails()
	//For now will keep items simple with just damage weapons 
	//Intro scene commented out for now, maybe add in later, might add more details to locations as well

#include <iostream>
#include "GameBoard.h"
#include "Player.h"
#include"Item.h"
#include"Location.h"
#include<vector>
using namespace std;


int main()
{
	GameBoard board;
	Player userPlayer;
	string userName;
	/*
	//Introduction scene
	cout << "Unkown: *muffled* Wake up! Wake up!" << endl;
	cout << "..." << endl;
	cin.get();
	cout << "Unkown: *loudly* Get up!" << endl;
	cin.get();
	cout << "Unkown: Oh I thought you were dead for a second. I saw your helicopter crash from afar I thought I'd come check on " <<
		"ya, you're crazy for coming out here. What's your name?" << endl;
	cin >> userName;
	userPlayer.setName(userName);
	cout << "Unkown: Well, " << userPlayer.getName() << " it was nice to meet you. But unless you get the 4 gems in time you're going to die" << endl;
	*/

	//Vector for the gameboard itself
	vector<vector<char>>* gameBoard;
	gameBoard = board.getGameBoard();
	//Generating the gem locations 
	board.generateMapDetails();
	//Printing board
	board.printGameBoard();

	bool isGameOver = false;
	string userDirection;
	//main game loop
	while (isGameOver == false) {
		cout << "Where would you like to move next? (North, Sout, East, West)" << endl;
		cin >> userDirection;

		//Input loop, getting and validting user input and moving the user and reprinting the map
		bool isValidInput = false;
		while (isValidInput == false) {
			if (userDirection == "North" || userDirection == "South" || userDirection == "East" || userDirection == "West") {
				isValidInput = true;
				board.moveLocation(userDirection);
			}
			else {
				cout << "Not valid input please enter again" << endl;
				cin >> userDirection;
			}
			cout << "------------------------------------" << endl;
			board.printGameBoard();
		}
		
	}

	return 0;
	
	

}


