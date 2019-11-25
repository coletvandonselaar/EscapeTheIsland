#include "Location.h"

//Getters
bool Location::getIsFinalRoom() const {
	return isFinalRoom;
}

bool Location::getIsStartingRoom() const {
	return isStartingRoom;
}

bool Location::getIsGemRoom() const {
	return isGemRoom;
}

bool Location::getHasVisited() const {
	return hasVisited;
}

bool Location::getIsCurrentLocation() const {
	return isCurrentLocation;
}

//Setters
void Location::setIsFinalRoom(bool i) {
	isFinalRoom = i;
}

void Location::setIsStartingRoom(bool s) {
	isStartingRoom = s;
}

void Location::setIsGemRoom(bool g) {
	isGemRoom = g;
}

void Location::setHasVisited(bool v) {
	hasVisited = v;
}

void Location::setIsCurrentLocation(bool c) {
	isCurrentLocation = c;
}
