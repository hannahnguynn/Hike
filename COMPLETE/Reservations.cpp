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

#include "Reservations.h"

#include "HikeList.h"
#include "MemberList.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int Reservations::addReservation(int memberId, const string& hikeName)
{
	int reservNumber = STARTING_NUMBER;

	if (count == 0)
	{
		Node* reservation = new Node(reservNumber, memberId,
						hikeName, nullptr, nullptr);
		first = last = reservation;
	}
	else
	{
		reservNumber += count;
		Node* reservation = new Node(reservNumber, memberId, hikeName,
						last, nullptr);
		last->setNext(reservation);
		last = reservation;
	}

	count++;
	return reservNumber;
}

Node* Reservations::findReservation(int resNumber) const
{
	Node* current = nullptr;

	if (resNumber < STARTING_NUMBER)
	{
		cerr << "This reservation does not exist.";
	}
	else
	{
		current = first;
		bool found = false;
		while (current != nullptr && !found)
		{
			if (current->getResNumber() == resNumber)
				found = true;
			else
				current = current->getNext();
		}
	}

	return current;
}

void Reservations::cancelReservation(int resNumber)
{
	if (count == 1)
	{
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else
	{
		Node* current = findReservation(resNumber);
		if (current == last)
		{
			last = last->getPrev();
		}
		else if (current == first)
		{
			first = first->getNext();
		}
		else
		{
			current->getPrev()->setNext(current->getNext());
			current->getNext()->setPrev(current->getPrev());
		}
		delete current;
		current = nullptr;
	}
}

void Reservations::printReservation(int resNumber, const HikeList& hike,
	const MemberList& member)
{
	Node* print = findReservation(resNumber);

	if (print != nullptr)
	{
		cout << endl;

		hike.printByHikeName(print->getHikeName());

		int point = member.getPoints(print->getMemberId());
		double price = hike.getPrice(print->getHikeName());
		
		if (point > 0)
		{
			double discount = price - (point / 100);
			cout << "\n\tDiscounted price using points: $"
				<< fixed << showpoint << setprecision(2) << discount
				<< endl;
		}
	}
	else
		cerr << "\nThis reservation does not exist." << endl;
}
void Reservations::clearList()
{
	Node* temp = first;

	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}

	last = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	clearList();
}
