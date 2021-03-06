#pragma once

#include "Entity.hpp"

#include <map>

using namespace std;

class Store
{
public:
	static map<unsigned int, Entity*> entities;
	static void printEntities();
	static Entity* getFirstMob();
};

map<unsigned int, Entity*> Store::entities;

inline void Store::printEntities() {
	cout << endl  << "Entities : " << endl;
	for (auto const& entity : Store::entities)
	{
		if(entity.second == nullptr)
		{
			continue;
		}
		cout
			<< entity.first  // (key)
			<< ':'
			<< entity.second->toString() // value 
			<< endl;
	}
}

inline Entity* Store::getFirstMob() {
	for (auto const& entity : Store::entities)
	{
		if (entity.second == nullptr)
		{
			continue;
		}

		if(entity.second->isMob())
		{
			return entity.second;
		}
	}

	return nullptr;
}