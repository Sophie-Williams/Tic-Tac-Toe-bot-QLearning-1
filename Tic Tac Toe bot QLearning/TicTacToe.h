#pragma once

#include <iostream>
#include <string>

#include "Helper.h"

using namespace std;

class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();

	void reset();
	bool makeMove(int pos);
	bool isFinished();
	int getCurrPlayer();
	int getWinner();
	string getBoardState();
	void printBoard();

private:
	char mGrid[3][3];
	char mSign[2];
	int mCurrPlayer;
	int mWinner;
};