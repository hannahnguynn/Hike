#ifndef	RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"

#include <string>

const int STARTING_NUMBER = 50001;

class Node
{
public:
	Node() : reservNumber(0), memberId(0),
		prev(nullptr), next(nullptr) {}
	Node(int NewReservNumber, int newMemberID, std::string newHikeName,
		Node* prevLink, Node* nextLink)
		: reservNumber(NewReservNumber), memberId(newMemberID),
		hikeName(newHikeName), prev(prevLink), next(nextLink) {}
	
	int getResNumber() const { return reservNumber; };
	int getMemberId() const { return memberId; };
	std::string getHikeName() const { return hikeName; };
	
	Node* getPrev() const { return prev; };
	Node* getNext() const { return next; };
	
	void setReservNumber(int newResNumber) 
					{ reservNumber = newResNumber; };
	void setMemberID(int newMemberID) { memberId = newMemberID; };
	void setHikeName(std::string newHikeName)
					{ hikeName = newHikeName; };
	void setPrev(Node* prevLink) { prev = prevLink; };
	void setNext(Node* nextLink) { next = nextLink; };
	
	~Node() {}

private:
	int reservNumber;   // reservation number
	int memberId;

	std::string hikeName;

	Node* prev;
	Node* next;
};

class Reservations
{
public:
	Reservations() : first(nullptr), last(nullptr), count(0) {}

	int addReservation(int memberID, const std::string& hikeName);

	void cancelReservation(int resNumber);

	void printReservation(int resNumber, const HikeList& hike, 
						const MemberList& member);

	void clearList();
	
	~Reservations();

private:
	Node* findReservation(int resNumber) const;

	Node* first;
	Node* last;

	int count;

};

#endif
