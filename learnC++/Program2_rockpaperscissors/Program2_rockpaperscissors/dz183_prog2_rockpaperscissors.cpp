/*
Name: David Zheng
NetID: dz183

Program Description: This program should emulate a rock-paper-scissor game. 
	There will be multiple rounds with a scoreboard.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;
using std::rand;
using std::string;

int run_game();
int get_player_choice();
int get_com_choice();
int determine_winner(int player, int com);
string str_choice(int choice);

const int Tie = 0;
const int Win = 1;
const int Lose = 2;
const int Rock = 1;
const int Paper = 2;
const int Scissors = 3;

int main()
{
	// This keeps track on whether to stop or continue
	char run = 'y';
	// Makes a random set of number for each execution
	srand(time(nullptr));

	int winner;

	cout << "Welcome to Rock, Paper, Scissors!";
	do
	{
		winner = run_game();
		if (winner == Win)
			cout << "Winner: Player!" << endl;
		else if (winner == Lose)
			cout << "Winner: Computer!" << endl;
		cout << endl;

		// Ask user if they want to stop the game
		cout << "Play another round? (y/n) ";
		cin >> run;
		cout << endl;

	} while (run == 'y');
}

int run_game()
{
	int player;
	int com;
	int champ;

	do
	{
		player = get_player_choice();
		cout << "You choose " << str_choice(player) << endl;
		com = get_com_choice();
		cout << "Computer choose " << str_choice(com) << endl;
		champ = determine_winner(player, com);
		cout << endl;
	} while (champ == Tie);

	return champ;
}

int get_player_choice()
{
	int player;
	cout << "What do you choose?" << endl; //Note: if a char is inputted, it'll go into a indefinite loop.
	cout << "1. Rock" << endl;
	cout << "2. Paper" << endl;
	cout << "3. Scissors" << endl;
	
	cout << "~~~~> ";
	cin >> player;

	//I was unsure how to repeat the block of code above without it including the error message
	while (player != 1 && player != 2 && player != 3) // Could have done (player < 1 && player > 3)
	{
		cout << "Error! Please choose a value between 1 and 3." << endl;
		cout << "What do you choose?" << endl;
		cout << "1. Rock" << endl;
		cout << "2. Paper" << endl;
		cout << "3. Scissors" << endl;

		cout << "~~~~> ";
		cin >> player;
	}

	return player;
}

int get_com_choice()
{
	// This will return a number from 1 to 3. (It ranges from 0-2, but with +1, it goes to 1 to 3)
	return rand() % 3 + 1;
}

int determine_winner(int player, int com)
{
	//Player Win
	if ((player == 1 && com == 3) || (player == 2 && com == 1) || (player == 3 && com == 2))
		return Win;
	//Computer Win
	else if ((player == 2 && com == 3) || (player == 3 && com == 1) || (player == 1 && com == 2))
		return Lose;
	//Tie
	else if ((player == 1 && com == 1) || (player == 2 && com == 2) || (player == 3 && com == 3))
		return Tie;
}

string str_choice(int choice) // Returns the choices
{
	if (choice == Rock)
		return "Rock";
	else if (choice == Paper)
		return "Paper";
	else if (choice == Scissors)
		return "Scissors";
	else
		return "<could not determine>";
}



