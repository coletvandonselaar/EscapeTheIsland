#include "GameBoard.h"
#include<cstdlib>
#include<ctime>
void GameBoard::printGameBoard() { 
	for (int i = 0; i < gameBoard.size(); i++) {
		for (int j = 0; j < gameBoard[i].size(); j++)
			cout << gameBoard[i][j] << "\t";
		cout << endl;
	}
}

//Returning a pointer to the game board so the main method can edit the board
vector<vector<char>>* GameBoard::getGameBoard() {
	return &gameBoard;
}

//Method called when the board is first created setting up the board for the game and generating where items and gems will be
void GameBoard::generateMapDetails() {

	//Filling the roomDetails vector with locations
	for (int i = 0; i < 4; i++) {
		//Creating a temporary vector to be added to the roomDetails vector or else when adding the new locations it will throw
			//std::out_of_range exception
		vector <Location> tempVect;
		roomDetails.push_back(tempVect);
		for (int j = 0; j < 4; j++) {
			Location tempLocation;
			tempLocation.setHasVisited(false);
			tempLocation.setIsCurrentLocation(false);
			roomDetails.at(i).push_back(tempLocation);
		}
	}

	//Variables for the users starting location
	int startingLocationY = 3;
	int startingLocationX = 0;

	//Variables for where the final location is at
	int finalLocationY = 1;
	int finalLocationX = 3;

	//Setting the starting location
	gameBoard.at(startingLocationY).at(startingLocationX) = CURRENT_LOCATION;
	roomDetails.at(startingLocationY).at(startingLocationX).setIsStartingRoom(true);
	roomDetails.at(startingLocationY).at(startingLocationX).setIsCurrentLocation(true);

	//Setting the final location user needs to get to in order to win the game
	roomDetails.at(finalLocationY).at(finalLocationX).setIsFinalRoom(true);

	int randomNumber;
	int amountOfGemsPlaced = 0;
	//Seed for random number
	unsigned seed = time(0);
	srand(seed);

	//Randomly generating gem locations
		//Gems can not be on the starting location or final location
	for (int i = 0; i < AMOUNT_OF_GEMS;) {
		bool didFailCheck = false;
		//Generating the random index where the gem will be placed for the row
		randomNumber = rand() % 3 + 0;
		//Going through some checks to see if the gem is eligible to be placed in the location
			//Checking if it's the starting location
		if (i == startingLocationY) {
			if (roomDetails.at(i).at(randomNumber).getIsStartingRoom()) {
				//It's the starting location so it tries generating a different one
				didFailCheck = true;
			}
		}
		//Checking if the gem is tring to be placed on the final room 
		else if (i == finalLocationY) {
			if (roomDetails.at(i).at(randomNumber).getIsFinalRoom()) {
				//Is in final room, trying another generation
				didFailCheck = true;
			}
		}
		
		//If all the checks pass, places the gem and goes onto the next row
		if (didFailCheck == false) {
			roomDetails.at(i).at(randomNumber).setIsGemRoom(true);
			i++;
		}
	}//end for loop
}//End method

void GameBoard::moveLocation(string userMove) {
	int playerX = 0;
	int playerY = 0;
	//Getting the current location of the player
	getPlayerLocationXY(playerX, playerY);
	
	//Checking input and changing location based off 
	if (userMove == "North") {
		//Making sure the user isn't at the top
		if (playerY == 0) {
			cout << "You can't go any further north!" << endl;
		}
		else {
			//Setting old location of the user
			setOldLocation(playerX, playerY);
			playerY -= 1;
			gameBoard.at(playerY).at(playerX) = CURRENT_LOCATION;
			roomDetails.at(playerY).at(playerX).setIsCurrentLocation(true);
			roomDetails.at(playerY).at(playerX).setHasVisited(true);
		}
	}
	else if (userMove == "South") {
		if (playerY == 3) {
				cout << "You can't go any further south!" << endl;
			}
		else {
			//Setting old location of the user
			setOldLocation(playerX, playerY);
			playerY += 1;
			gameBoard.at(playerY).at(playerX) = CURRENT_LOCATION;
			roomDetails.at(playerY).at(playerX).setIsCurrentLocation(true);
			roomDetails.at(playerY).at(playerX).setHasVisited(true);
		}
	}
	else if (userMove == "East") {
		if (playerX == 3) {
			cout << "You can't go any further east!" << endl;
		}
		else {
			setOldLocation(playerX, playerY);
			playerX += 1;
			gameBoard.at(playerY).at(playerX) = CURRENT_LOCATION;
			roomDetails.at(playerY).at(playerX).setIsCurrentLocation(true);
			roomDetails.at(playerY).at(playerX).setHasVisited(true);
		}
	}
	else if (userMove == "West") {
		if (playerX == 0) {
			cout << "You can't go any further west!" << endl;
		}
		else {
			setOldLocation(playerX, playerY);
			playerX -= 1;
			gameBoard.at(playerY).at(playerX) = CURRENT_LOCATION;
			roomDetails.at(playerY).at(playerX).setIsCurrentLocation(true);
			roomDetails.at(playerY).at(playerX).setHasVisited(true);
		}
	}

	//Checking if the user found a gem
	if (roomDetails.at(playerY).at(playerX).getIsGemRoom()) {
		cout << "You found a gem!" << endl;
	}
}

//Method to find the players current location and changes the playerX and playerY to correct coordinates
void GameBoard::getPlayerLocationXY(int& playerX, int& playerY) {

	//Finding player location
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (roomDetails.at(i).at(j).getIsCurrentLocation()) {
				playerX = j;
				playerY = i;
				break;
			}
		}
	}
}

void GameBoard::setOldLocation(int playerX, int playerY) {
	//Changing the current location to a visited location
	roomDetails.at(playerY).at(playerX).setIsCurrentLocation(false);
	roomDetails.at(playerY).at(playerX).setHasVisited(true);
	gameBoard.at(playerY).at(playerX) = VISITED_LOCATION;
}