#pragma once
#include<string>
#include<vector>
#include "Item.h"
using namespace std;
class Player
{
public:
	//Getters
	string getName();
	//Setters
	void setName(string);
private:
	string name;
	vector<Item> inventory;
};

