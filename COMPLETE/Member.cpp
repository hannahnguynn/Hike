#include "Member.h"

#include <iostream>

using namespace std;


void Member::addPoints(int pointsCount) {
	points += pointsCount;
}

void Member::setID(int idNumber) {
	iD = idNumber;
}

int Member::getID() const {
	return iD;
}

string Member::getLName() const {
	return lName;
}

int Member::getPoints() const {
	return points;
}

bool Member::operator<(const Member& otherMember) const
{
	return (iD < otherMember.iD);
}

void Member::printMember() const
{
	cout << "\t" << lName << ", " << fName << "\n";
	cout << "\t" << "Points available: " << points << endl;
}


