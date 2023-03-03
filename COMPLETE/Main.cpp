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

#include "Hike.h"
#include "HikeList.h"
#include "Member.h"
#include "MemberList.h"
#include "Reservations.h"
#include "Interface.h"
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationsReader.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    HikeList hike = HikeList();
    getHikeData(hike);
    
    MemberList member = MemberList();
    getMemberData(member);

    Reservations reserves = Reservations();
    getReservationData(reserves);
    
    displayMenu();
    processReservation(hike, member, reserves);
    
    return 0;

}