#include "Interface.h"
#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayMenu()
{
    cout << "***************************************************"
        << "\n\t\tHIKING IN THE US\n"
        << "***************************************************\n\n"
        << "\t1. Browse by location\n"
        << "\t2. Browse by duration\n"
        << "\t3. Browse by difficulty\n"
        << "\t4. Browse by price\n"
        << "\t5. Make a reservation\n"
        << "\t6. View reservation\n"
        << "\t7. Cancel reservation\n"
        << "\t8. Exit\n" << endl;
}

void processReservation(HikeList& hike, MemberList& member, Reservations& reservation)
{
    cout << "Please make a selection: ";

    int selection = 0;
    cin >> selection;
    cout << endl;

    while (selection != 8)
    {
        if (selection == 1)
        {
            chooseByLocation(hike, member, reservation);
        }
        else if (selection == 2)
        {
            chooseByDuration(hike, member, reservation);
        }
        else if (selection == 3)
        {
            chooseByDifficulty(hike, member, reservation);
        }
        else if (selection == 4)
        {
            chooseByPrice(hike, member, reservation);
        }
        else if (selection == 5)
        {
            makeReservation(hike, member, reservation);
        }
        else if (selection == 6)
        {
            viewReservation(hike, member, reservation);
        }
        else if (selection == 7)
        {
            cancelReservation(hike, member, reservation);
        }

        system("Pause");
        cout << endl;
        displayMenu();

        cout << "Please make a selection: ";
        cin >> selection;
        cout << endl;
    }

    cout << "Thank you for visiting!" << endl;
}

void chooseByLocation(HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    hike.printAllLocations();

    cout << "\nChoose a location: ";
    string location;
    cin >> location;

    cout << endl;

    hike.printByLocation(location);
    askToReserve(hike, member, reservation);
}

void chooseByDuration(HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    hike.printByDuration();
    
    cout << "\nHow many days are you considering? ";

    int days = 0;
    cin >> days;
    cout << endl;

    hike.printByDuration(days);
    askToReserve(hike, member, reservation);
}

void chooseByDifficulty(HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Choose difficulty level:\n\n"
        << "\te. easy\n" << "\tm. moderate\n"
        << "\ts. strenous\n\n" << "Your choice: ";

    char choice = 'e';
    cin >> choice;

    cout << endl;

    hike.printByDifficulty(choice);

    cout << endl;

    askToReserve(hike, member, reservation);
}

void chooseByPrice(HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    hike.printByPrice();
    cout << endl;
    askToReserve(hike, member, reservation);
}

int askIfMember(MemberList& member)
{
    cout << "Are you a member? (y/n) ";
    char answer = 'e';
    cin >> answer;

    int iD = 0;

    if (answer == 'y')
    {
        cout << "\nWhat is you member ID number? ";
        cin >> iD;

        cout << "\nWhat is your last name? ";
        string lName;
        cin >> lName;

        cout << endl;

        member.printMember(iD, lName);
    }
    else
    {
        iD = addNewMember(member);
    }
    cout << endl;
    return iD;

}

int addNewMember(MemberList& member)
{
    cout << "\n\tLet's add you to the member list!\n"
        << "\t\tWhat is your first name? ";
    string fName;
    cin >> fName;

    cout << "\t\tWhat is your last name? ";
    string lName;
    cin >> lName;
    cout << endl;

    member.addMember(fName, lName);
    int iD = member.getLastID();

    cout << "\tWelcome to the club!\n"
        << "\t\tYour member ID number is: "
        << iD << endl;

    return iD;

}

void makeReservation(HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    int iD = askIfMember(member);
    cout << "Which hike would you like to reserve (hike name)? ";

    string hikeName;
    cin >> hikeName;

    cout << endl;

    hike.printByHikeName(hikeName);

    int reserveNum = reservation.addReservation(iD, hikeName);
    double price = hike.getPrice(hikeName);
    int points = member.getPoints(iD);

    double discount = price - (points / 100);
    
    if (points > 0)
    {
        cout << "\n\tDiscounted price using points: $"
            << fixed << setprecision(2) << discount<< endl;
    }
    cout << "\n\tBefore proceeding, please make a note of your"
        << " reservation number.\n" 
        << "\t  Reservation #: " << reserveNum 
        << "\n\n( *** Will continue to scheduling and payment. *** )\n" 
        << endl;
}

void viewReservation(HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Enter reservation #: ";

    int resNum;
    cin >> resNum;

    reservation.printReservation(resNum, hike, member);
    cout << endl;
}

void cancelReservation(HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Enter reservation #: ";

    int reserveNum = 0;
    cin >> reserveNum;

    reservation.printReservation(reserveNum, hike, member);

    cout << "\nAre you sure you want to cancel this reservation? (y/n) ";
    char answer = 'e';
    cin >> answer;

    cout << endl;

    if (answer == 'y')
    {
        reservation.cancelReservation(reserveNum);
        cout << "Reservation #" << reserveNum
            << " has been canceled.\n" << endl;
    }
}

void askToReserve(HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Would you like to make a reservation? (y/n) ";
    char answer = 'e';
    cin >> answer;

    cout << endl;

    if (answer == 'y')
    {
        makeReservation(hike, member, reservation);
    }
}
