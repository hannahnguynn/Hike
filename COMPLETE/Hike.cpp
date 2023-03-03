#include "Hike.h"

#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(ostream& out, const Hike& hike)
{
	std::string diff;

	if (hike.difficulty == 'e') { diff = "easy"; }
	else if (hike.difficulty == 'm') { diff = "moderate"; }
	else if (hike.difficulty == 's') { diff = "strenuous"; }

	out << "\t" << hike.name << " (" << hike.location << ")"
		<< "\n\t  Difficulty: " << diff
		<< "\n\t  Duration: " << hike.duration << " day(s)";

	return out;
}

Hike::Hike()
{
	duration = 0;
	difficulty = 'e';
}

Hike::Hike(const std::string& newLocation, const std::string& newName,
	int newDuration, char newDifficulty)
{
	location = newLocation;
	name = newName;
	duration = newDuration;
	difficulty = newDifficulty;
}

string Hike::getLocation() const { return location; }

string Hike::getName() const { return name; }

int Hike::getDuration() const { return duration; }

char Hike::getDifficulty() const { return difficulty; }

bool Hike::operator<(const Hike& hike) const
{
	return (location < hike.location);
}

Hike::~Hike() {}
