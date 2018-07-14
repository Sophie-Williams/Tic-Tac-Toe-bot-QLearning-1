#include <iostream>

#include "TicTacToe.h"
#include "QLearning.h"
#include "Random.h"
#include "FileIO.h"

using namespace std;

TicTacToe game;
QLearning QBot(.5, .8);
Random RBot;

string QPath = "File\\Text\\QValue.txt";
string SPath = "File\\Text\\score cpuVSrand.txt";

vector<int> scores;

int main()
{
	QBot.readQValue(QPath);

	int n, pos, win = 0, lose = 0, tie = 0;
	cout << "Enter no of trial: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		game.reset();
		while (!game.isFinished())
		{
			if (game.getCurrPlayer() == 2)
			{
				pos = QBot.getAction(game.getBoardState());
				game.makeMove(pos + 1);
				QBot.addReward(0);
			}
			else
			{
				pos = RBot.getAction(game.getBoardState());
				game.makeMove(pos + 1);
			}
		}

		system("cls");
		game.printBoard();
		cout << "Player " << game.getWinner() << " wins!" << endl;
		cout << "Win: " << win << endl;
		cout << "Lose: " << lose << endl;
		cout << "Tie:" << tie << endl;

		QBot.getAction(game.getBoardState());
		if (game.getWinner() == 2)
		{
			QBot.addReward(10);
			win++;
		}
		else if (game.getWinner() == 1)
		{
			QBot.addReward(-10);
			lose++;
		}
		else
		{
			QBot.addReward(-1);
			tie++;
		}

		QBot.update();
		scores.push_back(game.getWinner());
	}

	QBot.saveQValue(QPath);

	for (int i = 0; i < scores.size(); i++)
	{
		FileIO::saveScore(SPath, scores[i]);
	}

	cin.ignore();
	cin.ignore();
}