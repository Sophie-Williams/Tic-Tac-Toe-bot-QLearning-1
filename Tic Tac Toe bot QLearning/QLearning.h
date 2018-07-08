#pragma once

#include <iostream>
#include <float.h>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "Helper.h"

using namespace std;

#define MAX_STATE 20000
#define MAX_ACTION 9

class QLearning
{
public:
	QLearning(double learningRate, double discount);
	~QLearning();

	int getAction(string state);
	void addReward(int reward);
	void update();
	void readQValue(string path);
	void saveQValue(string path);

private:
	int mStateCounter;
	double mLearningRate, mDiscount;
	double mQValue[MAX_STATE][MAX_ACTION];
	map<string, int> mStateID;
	vector<string> mStates;
	vector<int> mActions;
	vector<int> mRewards;
};