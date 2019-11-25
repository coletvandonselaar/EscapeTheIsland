#pragma once
#include "Item.h"
#include<vector>
#include<string>
using namespace std;
class Location
{
public:
	//Setters
	void setRoomDescription(string desc);
	void setItemsInRoom(vector<Item> items);
	void setIsGemRoom(bool gem);
	void setIsFinalRoom(bool finalRoom);
	void setIsStartingRoom(bool);
	void setHasVisited(bool);
	void setIsCurrentLocation(bool);

	//Getters
	string getRoomDescription();
	vector<Item> getItemsInRoom() const;
	bool getIsGemRoom() const;
	bool getIsFinalRoom() const;
	bool getIsStartingRoom() const;
	bool getHasVisited() const;
	bool getIsCurrentLocation() const;


private:
	string roomDescription;
	vector<Item> itemsInRoom;
	bool isGemRoom;
	bool isFinalRoom;
	bool isStartingRoom;
	bool isCurrentLocation;
	bool hasVisited;
};

