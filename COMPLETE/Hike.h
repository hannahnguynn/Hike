/*
	std

	Barron, Evelin
	Garel, Bronson
	Nguyen, Hannah
	Pham, Jayson

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

class Hike
{
	friend std::ostream& operator<<(std::ostream& out, const Hike& hike);

public:
	Hike();
	Hike(const std::string& newLocation, const std::string& newName,
		int newDuration, char newDifficulty);

	std::string getLocation() const;
	std::string getName() const;
	int getDuration() const;
	char getDifficulty() const;

	bool operator<(const Hike& hike) const;

	~Hike();

private:
	std::string location,
		name;
	int duration; 
	char difficulty;
};
#endif