#ifndef INTERFACE_H
#define INTERFACE_H

#include "Hike.h"
#include "HikeList.h"
#include "Member.h"
#include "MemberList.h"
#include "Reservations.h"

#include <string>

void displayMenu();

void processReservation(HikeList&, MemberList&, Reservations&);

void chooseByLocation(HikeList&, MemberList&, Reservations&);
void chooseByDuration(HikeList&, MemberList&, Reservations&);
void chooseByDifficulty(HikeList&, MemberList&, Reservations&);
void chooseByPrice(HikeList&, MemberList&, Reservations&);

int askIfMember(MemberList&);
int addNewMember(MemberList&);

void makeReservation(HikeList&, MemberList&, Reservations&);
void viewReservation(HikeList&, MemberList&, Reservations&);
void cancelReservation(HikeList&, MemberList&, Reservations&);

void askToReserve(HikeList&, MemberList&, Reservations&);


#endif
