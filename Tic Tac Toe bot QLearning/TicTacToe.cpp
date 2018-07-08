#include "TicTacToe.h"



TicTacToe::TicTacToe()
{
	reset();
}


TicTacToe::~TicTacToe()
{
}

void TicTacToe::reset()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int pos = (i * 3) + j;
			mGrid[i][j] = '1' + pos;
		}
	}
	mSign[0] = 'X';
	mSign[1] = 'O';
	mCurrPlayer = 0;
	mWinner = -1;
}

bool TicTacToe::makeMove(int pos)
{
	pos--;
	int row = pos / 3;
	int col = pos % 3;
	if (!isFinished() && row >= 0 && row<3 && col >= 0 && col<3 && Helper::validMove(getBoardState(), pos))
	{
		mGrid[row][col] = mSign[mCurrPlayer++];
		mCurrPlayer %= 2;
		return true;
	}
	return false;
}

bool TicTacToe::isFinished()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (mGrid[i][0] == mSign[j] && mGrid[i][1] == mSign[j] && mGrid[i][2] == mSign[j])
			{
				mWinner = j;
				return true;
			}
		}

		for (int j = 0; j < 2; j++)
		{
			if (mGrid[0][i] == mSign[j] && mGrid[1][i] == mSign[j] && mGrid[2][i] == mSign[j])
			{
				mWinner = j;
				return true;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if ((mGrid[0][0] == mSign[i] && mGrid[1][1] == mSign[i] && mGrid[2][2] == mSign[i]) || (mGrid[0][2] == mSign[i] && mGrid[1][1] == mSign[i] && mGrid[2][0] == mSign[i]))
		{
			mWinner = i;
			return true;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (Helper::validMove(getBoardState(), i))
		{
			return false;
		}
	}

	return true;
}

int TicTacToe::getCurrPlayer()
{
	return mCurrPlayer + 1;
}

int TicTacToe::getWinner()
{
	return mWinner + 1;
}

string TicTacToe::getBoardState()
{
	string boardState = "";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			boardState += mGrid[i][j];
		}
	}

	return boardState;
}

void TicTacToe::printBoard()
{
	for (int i = 0; i < 12; i++)
	{
		cout << "=";
	}
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		if (i != 0)
		{
			for (int j = 0; j <= 10; j++)
			{
				cout << "-";
			}
			cout << endl;
		}

		cout << " " << mGrid[i][0] << " | " << mGrid[i][1] << " | " << mGrid[i][2] << endl;
	}

	for (int i = 0; i < 12; i++)
	{
		cout << "=";
	}
	cout << endl;
}