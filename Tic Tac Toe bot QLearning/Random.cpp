#include "Random.h"



Random::Random()
{
}


Random::~Random()
{
}

int Random::getAction(string state)
{
	vector<int> v;
	for (int i = 0; i < 9; i++)
	{
		if (Helper::validMove(state, i))
		{
			v.push_back(i);
		}
	}

	int pos = rand() % v.size();
	return v[pos];
}