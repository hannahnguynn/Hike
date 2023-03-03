#include "MemberList.h"
#include "Member.h"

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

MemberList::MemberList()
{
    mList = new set<Member>;
}

void MemberList::addMember(const string& first, const string& last)
{
    Member newMember = Member(first, last);

    int membersId = MEMBER_ID;

    if (mList->size() == 0)
    {
        newMember.setID(MEMBER_ID);
    }
    else
    {
        int size = static_cast<int>(mList->size());
        int membersId = MEMBER_ID + size;
        newMember.setID(membersId);
    }
    mList->insert(newMember);
}

void MemberList::addMember(const string& first, const string& last,
                            int pts)
{
    Member newMember = Member(first, last);

    newMember.addPoints(pts);

    if (mList->size() == 0)
    {
        newMember.setID(MEMBER_ID);
    }
    else
    {
        int size = static_cast<int>(mList->size());
        int membersId = MEMBER_ID + size;
        newMember.setID(membersId);

    }

    mList->insert(newMember);
}

int MemberList::getLastID() const
{
    return mList->rbegin()->getID();
}

int MemberList::getPoints(int memberId) const
{
    auto iter = find_if(mList->begin(), mList->end(),
        [memberId](const auto& mElem) 
        { return mElem.getID() == memberId; });
   
    return iter->getPoints();
}

void MemberList::printMember(int memberId, const string& last) const
{
    auto iter = find_if(mList->begin(), mList->end(),
        [memberId, &last](const auto& mElem) {return 
        (mElem.getID() == memberId) && (mElem.getLName() == last); });

    iter->printMember();

    cout << "\t" << "Membership # " << memberId << "\n";
}

void MemberList::clearList()
{
    mList->clear();
}

MemberList::~MemberList()
{
    delete mList;
}
