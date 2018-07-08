#include <iostream>

#include "TicTacToe.h"
#include "QLearning.h"
#include "Random.h"

using namespace std;

TicTacToe game;
QLearning QBot(.5, .8);
Random RBot;

string path = "File\\Text\\QValue.txt";

int main()
{
	QBot.readQValue(path);

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
	}

	QBot.saveQValue(path);
	cin.ignore();
	cin.ignore();
}