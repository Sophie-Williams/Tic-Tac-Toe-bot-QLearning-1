#pragma once

#include <string>
#include <vector>

#include "Helper.h"

using namespace std;

class Random
{
public:
	Random();
	~Random();

	int getAction(string state);
};