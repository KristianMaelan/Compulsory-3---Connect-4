#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <array>
#include <string>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

std::string gameboard[6][7];
std::string player1{};
std::string player2{};
std::string winner{};
std::string loser{};
char keepPlaying{};
bool restart = false;

void resetGame();
void gameboardprint();
void gameboardfileprint();
std::string gameLoop(std::string, std::string);
bool winTesting();

int animation(std::string, int);


//For score saving
std::streampos begin, end;
std::ofstream ScoreFile("../winners.txt", std::ios::app);

void resetGame() {
	player1 = {};
	player2 = {};
	winner = {};
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++) {
			gameboard[i][j] = "*";
		}
	}
}

void gameboardprint() {
	cout << "\t\t\t| 1 2 3 4 5 6 7  |" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "\t\t\t| ";
		for (int j = 0; j < 7; j++)
		{
			cout << gameboard[i][j] << " ";
		}
		cout << " |" << endl;
	}
}

void gameboardfileprint() {
	ScoreFile << "\t\t\t| 1 2 3 4 5 6 7  |" << endl;
	for (int i = 0; i < 6; i++)
	{
		ScoreFile << "\t\t\t| ";
		for (int j = 0; j < 7; j++)
		{
			ScoreFile << gameboard[i][j] << " ";
		}
		ScoreFile << " |" << endl;
	}
	ScoreFile << "\n\n" << endl;
}


std::string gameLoop(std::string p1, std::string p2) {
	p1 = 'X';
	p2 = 'O';

	for (int gamelength = 0; gamelength < 42; gamelength++) {
		system("cls");
		if (gamelength % 2 == 0) { //player 1
			gameboardprint();
			cout << "\t\t" << player1 << ", your turn! Choose a number according to where you want to place a piece." << endl;
			bool acceptedmove = 0;
			do {
				char choice{};
				choice = _getch();
				switch (choice)
				{
				case '1':
					if (gameboard[0][0] != "X" || "O") {
						acceptedmove = 1;
						animation("X", 0);
					}
					break;
				case '2':
					if (gameboard[0][1] != "X" || "O") {
						acceptedmove = 1;
						animation("X", 1);
					}
					break;
				case '3':
					if (gameboard[0][2] != "X" || "O") {
						acceptedmove = 1;
						animation("X", 2);
					}
					break;
				case '4':
					if (gameboard[0][3] != "X" || "O") {
						acceptedmove = 1;
						animation("X", 3);
					}
					break;
				case '5':
					if (gameboard[0][4] != "X" || "O") {
						acceptedmove = 1;
						animation("X", 4);
					}
					break;
				case '6':
					if (gameboard[0][5] != "X" || "O") {
						acceptedmove = 1;
						animation("X", 5);
					}
					break;
				case '7':
					if (gameboard[0][6] != "X" || "O") {
						acceptedmove = 1;
						animation("X", 6);
					}
					break;
				default:
					cout << "Wrong input... Try again" << endl;
					break;
				}
			} while (!acceptedmove);
			if (winTesting()) { winner = player1; loser = player2; break; }
		}
		else
		{
			gameboardprint();
			cout << "\t\t" << player2 << ", your turn! Choose a number according to where you want to place a piece." << endl;
			char choice = 0;
			bool acceptedmove = 0;
			do {
				choice = _getch();
				switch (choice)
				{
				case '1':
					if (gameboard[0][0] != "X" || "O") {
						acceptedmove = 1;
						animation("O", 0);
					}
					break;
				case '2':
					if (gameboard[0][1] != "X" || "O") {
						acceptedmove = 1;
						animation("O", 1);
					}
					break;
				case '3':
					if (gameboard[0][2] != "X" || "O") {
						acceptedmove = 1;
						animation("O", 2);
					}
					break;
				case '4':
					if (gameboard[0][3] != "X" || "O") {
						acceptedmove = 1;
						animation("O", 3);
					}
					break;
				case '5':
					if (gameboard[0][4] != "X" || "O") {
						acceptedmove = 1;
						animation("O", 4);
					}
					break;
				case '6':
					if (gameboard[0][5] != "X" || "O") {
						acceptedmove = 1;
						animation("O", 5);
					}
					break;
				case '7':
					if (gameboard[0][6] != "X" || "O") {
						acceptedmove = 1;
						animation("O", 6);
					}
					break;
				default:
					cout << "Wrong input... Try again" << endl;
					break;
				}
			} while (!acceptedmove);
			if (winTesting()) { winner = player2; loser = player1; break; }
		}
	};
	return winner;
}

int animation(std::string player, int col) {
	system("cls");
	//gameboardprint();
	Sleep(400);
	for (int i = 0; i < 6; i++) {
		gameboard[i][col] = player;
		if ((gameboard[i + 1][col] == "X") || (gameboard[i + 1][col] == "O")) {
			if (i >= 1) {
				gameboard[i - 1][col] = '*';
			}
			gameboard[i][col] = player;
			return 1;
		}
		if (i >= 1) {
			gameboard[i - 1][col] = '*';
		}
		gameboardprint();
		Sleep(200);
		system("cls");
	}
	return 0;
}

bool winTesting() {
	//Horisontal win condition
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 6; i++) {
			if ((gameboard[i][j] == "X" && gameboard[i][j + 1] == "X" && gameboard[i][j + 2] == "X" && gameboard[i][j + 3] == "X")
				|| (gameboard[i][j] == "O" && gameboard[i][j + 1] == "O" && gameboard[i][j + 2] == "O" && gameboard[i][j + 3] == "O")) {
				return true;
			}
		}
	}
	//Vertical win condition
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			if ((gameboard[i][j] == "X" && gameboard[i + 1][j] == "X" && gameboard[i + 2][j] == "X" && gameboard[i + 3][j] == "X")
				|| (gameboard[i][j] == "O" && gameboard[i + 1][j] == "O" && gameboard[i + 2][j] == "O" && gameboard[i + 3][j] == "O")) {
				return true;
			}
		}
	}
	//Descending diagonal win condition, pain to test :(
	for (int i = 3; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			if ((gameboard[i][j] == "X" && gameboard[i - 1][j + 1] == "X" && gameboard[i - 2][j + 2] == "X" && gameboard[i - 3][j + 3] == "X")
				|| (gameboard[i][j] == "O" && gameboard[i - 1][j + 1] == "O" && gameboard[i - 2][j + 2] == "O" && gameboard[i - 3][j + 3] == "O"))
				return true;
		}
	}
	//Ascending diagonal win condition, ALSO a pain to test :( but it works <3
	for (int i = 3; i < 6; i++) {
		for (int j = 3; j < 7; j++) {
			if ((gameboard[i][j] == "X" && gameboard[i - 1][j - 1] == "X" && gameboard[i - 2][j - 2] == "X" && gameboard[i - 3][j - 3] == "X")
				|| (gameboard[i][j] == "O" && gameboard[i - 1][j - 1] == "O" && gameboard[i - 2][j - 2] == "O" && gameboard[i - 3][j - 3] == "O"))
				return true;
		}
	}

	//if no win condition is satisfied, returns false
	return false;
}

