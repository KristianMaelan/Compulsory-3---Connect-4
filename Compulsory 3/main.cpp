#include "Declarations.h"

int main() {
	do
	{
	resetGame();
	cout << "\t\t\tWelcome to Conect 4!\n\n\tTo see previous winners, open winners.txt located in project root." << endl;
	cout << "\tThis is the gameboard, numbers represent where you want to place the next piece." << endl;
	cout << "\tGet 4 in a row before your opponent!\n\tPlayer 1 is X, player 2 is O!\n\n" << endl;
	gameboardprint();
	system("pause");
	system("cls");
	cout << "\tPlease enter the name of player 1: " << endl;
	cin >> player1;
	cout << "\n\tPlease enter the name of player 2: " << endl;
	cin >> player2;

	cout << "Starting the game with " << player1 << " vs " << player2 << "!" << endl;
	system("pause");
	gameLoop(player1, player2);
	gameboardprint();
	cout << "\tCongratulations " << winner << "! You are this rounds winner!!!\n\tTo see previous victors open winners in project root." << endl;
	cout << "\tSaving result to file..." << endl;
	Sleep(3500);


	ScoreFile << "\t" << winner << " won against " << loser << "!" << " With this board: " << endl;
	gameboardfileprint();
	ScoreFile.close();

	cout << "Want to keep playing? Press Y/y. Press Q/q to quit" << endl;
	
	keepPlaying = _getch();
	switch (keepPlaying)
	{
	case 'y':
		restart = true;
		break;
	case 'q':
		restart = false;
		break;
	default:
		restart = true;
		break;
	}
	system("cls");
	} while (restart);
	return 0;
}