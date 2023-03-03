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

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservationList(ifstream& infile,
	Reservations& reservationsList)
{
	int id = 0;
	string hikeName;

	while (!infile.eof())
	{
		infile >> id >> hikeName;
		reservationsList.addReservation(id, hikeName);
	}
}

void getReservationData(Reservations& reservationsList)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservationList(infile, reservationsList);

	infile.close();
}