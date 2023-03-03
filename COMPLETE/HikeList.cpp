#include "Hike.h"
#include "HikeList.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

HikeList::HikeList() {} 

void HikeList::addHike(const Hike& newHike, double price) 
{
	hikeMap.insert(make_pair(newHike, price));
}

void HikeList::addHike(const string& hikeLocation, const string& hikeName,
	int hikeDuration, char hikeDifficulty, double hikePrice)
{
	Hike temp = Hike(hikeLocation, hikeName, hikeDuration,
					hikeDifficulty);
	hikeMap.insert(make_pair(temp, hikePrice));
}

double HikeList::getPrice(const string& hikeName) const
{
	auto search = find_if(hikeMap.begin(), hikeMap.end(),
		[&hikeName] (const auto& iter)
		{ return (hikeName == iter.first.getName()); });

	return  search->second;
}

void HikeList::printAllLocations() const
{
	for (auto iter = hikeMap.cbegin(), end = hikeMap.cend();
		iter != end; iter = hikeMap.upper_bound(iter->first))
	{
		cout << "\t" << (iter->first).getLocation()<< endl;
	}
}

void HikeList::printByLocation(const string& hikeLocation) const
{
	auto iter = find_if(hikeMap.begin(), hikeMap.end(), 
		[&hikeLocation] (const pair<const Hike&, double>& otherLoc)
		{ return (hikeLocation == otherLoc.first.getLocation()); });

	auto iterEnd = hikeMap.end();

	while (iter != iterEnd)
	{ 
		if ((iter->first).getLocation() == hikeLocation)
		{
			cout << iter->first << "\n\t  "
				<< "Price (per person): $ "
				<< fixed << showpoint << setprecision(2) << iter->second
				<< "\n" << endl;
		}
		iter++;
	}
}

void HikeList::printByDuration() const  
{
	multimap<int, string> temp;
	string tempStr;

	for (const auto& findDuration : hikeMap)
	{
		tempStr = findDuration.first.getName() + ", " 
				+ findDuration.first.getLocation();

		temp.insert(pair<int, string>
			(findDuration.first.getDuration(), tempStr));
	}

	auto iter = temp.begin();
	auto iterE = temp.end();

	for_each(iter, iterE,
		[](const auto& elem)
		{ cout << "\t(" << elem.first << ") "
		<< elem.second << endl; });
}

void HikeList::printByDuration(int days) const 
{
	for (const auto& elem : hikeMap)
	{
		if (elem.first.getDuration() == days)
		{
			cout << elem.first << "\n" << endl;
		}
	}
}

void HikeList::printByDifficulty(char diff) const
{
	auto iter = find_if(hikeMap.begin(), hikeMap.end(),
		[&diff](const pair<const Hike&, double>& otherLoc)
		{ return (diff == otherLoc.first.getDifficulty()); });

	auto iterEnd = hikeMap.end();

	cout << "\t(difficulty level)" << endl;

	while (iter != iterEnd)
	{
		if ((iter->first).getDifficulty() == diff)
		{
			cout << "\t(" << diff << ") " << iter->first.getName()
				<< ", " << iter->first.getLocation() << endl;
		}
		iter++;
	}
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> temp;
	for (const auto& x : hikeMap)
	{
		temp.emplace(x.second, pair<string, string>(x.first.getName(),
			x.first.getLocation()));
	}

	for (const auto& x : temp)
	{
		if (x.first < 1000)
		{
			cout << "\t$  " << fixed << showpoint << setprecision(2) << x.first
				<< " - " << x.second.second << " (" << x.second.first << ")"
				<< endl;
		}
		else
		{
			cout << "\t$ " << fixed << showpoint << setprecision(2) << x.first
				<< " - " << x.second.second << " (" << x.second.first << ")"
				<< endl;
		}
	}
}

void HikeList::printByHikeName(const string& hikeName) const
{
	auto iter = find_if(hikeMap.cbegin(), hikeMap.cend(),
		[&hikeName](const pair<const Hike&, double>& otherLoc)
		{ return (hikeName == otherLoc.first.getName()); });

	cout << iter->first << "\n\t  $" << fixed << showpoint 
		<< setprecision(2) << iter->second << endl;
}

void HikeList::clearList()
{
	hikeMap.clear();
} 
