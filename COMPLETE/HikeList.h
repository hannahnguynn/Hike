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

#ifndef HIKELIST_H
#define HIKELIST_H

#include "Hike.h"

#include <string>
#include <map>

class HikeList
{
public:
	HikeList();

	void addHike(const Hike& newHike, double price);
	void addHike(const std::string& hikeLocation, 
		const std::string& hikeName, int hikeDuration,
		char hikeDifficulty, double hikePrice);

	double getPrice(const std::string& hikeName) const;

	void printAllLocations() const;
	void printByLocation(const std::string& location) const;
	void printByDuration() const;
	void printByDuration(int days) const;
	void printByDifficulty(char diff) const;
	void printByPrice() const;
	void printByHikeName(const std::string&) const;

	void clearList();

private:
	std::multimap<Hike, double> hikeMap;
};
#endif