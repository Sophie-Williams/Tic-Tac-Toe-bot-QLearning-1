#include <iostream>

#include "TicTacToe.h"

using namespace std;

int main()
{
	TicTacToe game;

	int n, pos;
	cout << "Enter no of trial: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		game.reset();
		while (!game.isFinished())
		{
			system("cls");
			game.printBoard();

			cout << "Current player: " << game.getCurrPlayer() << endl;
			cout << "Enter pos: ";
			cin >> pos;

			if (!game.makeMove(pos))
			{
				cout << "Invalid move" << endl;
				cout << "Press ENTER to continue" << endl;
				cin.ignore();
				cin.ignore();
			}
		}

		system("cls");
		game.printBoard();
		cout << "Player " << game.getWinner() << " wins!" << endl;
		cout << "Press ENTER to reset" << endl;
		cin.ignore();
		cin.ignore();
	}
}