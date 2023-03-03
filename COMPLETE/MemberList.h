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

#ifndef MemberList_H
#define MemberList_H

#include "Member.h"

#include <set>
#include <string>

const int MEMBER_ID = 111;

class MemberList
{
public:
    MemberList();

    void addMember(const std::string& first, const std::string& last);
    void addMember(const std::string& first, const std::string& last, 
                    int pts);

    int getLastID() const;
    int getPoints(int member_ID) const;

    void printMember(int member_ID, const std::string& last) const;

    void clearList();

    ~MemberList();

private:
    std::set<Member>* mList;
};

#endif