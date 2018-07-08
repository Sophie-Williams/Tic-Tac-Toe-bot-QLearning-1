#include "Helper.h"



bool Helper::validMove(string state, int move)
{
	if (state[move] >= '1' && state[move] <= '9')
	{
		return true;
	}
	return false;
}

Helper::Helper()
{
}


Helper::~Helper()
{
}