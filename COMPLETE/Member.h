#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
	Member() : iD(0), points(0) {}
	Member(const std::string& newFName,  const std::string& newLName)
		: fName(newFName), lName(newLName), iD(0), points(0) {}

	void addPoints(int pointsCount);
	void setID(int idNumber);

	int getID() const;
	std::string getLName() const;
	int getPoints() const;

	bool operator<(const Member& otherMember) const;

	void printMember() const;

private:
	int iD;

	std::string lName;
	std::string fName;

	int points;
};
#endif 
