#include <iostream>
#include <vector>;
#include <fstream>;
#include <string>;
using namespace std;

/*
	#Game XO

	//DrawGame
	~~~~~~~~~~~~~~
	# X # X # X #
	~~~~~~~~~~~~~~
	# X # X # X #
	~~~~~~~~~~~~~~
	# X # X # X #
	~~~~~~~~~~~~~~

*/
void Print()
{
	cout << "########################################## \n\n";
	cout << "################ Game XO #################\n \n";
	cout << "------------------------------------------\n";
	cout << "1 - You Now PLay With Computer .  " << endl;
	cout << "2 - You Player 'X'.  " << endl;
	cout << "3 - Coputer Player 'O'.  " << endl;
	cout << "------------------------------------------\n";
	cout << "\n########################################## \n";
}

int RandomNumber(int from = 0, int to = 3)
{
	return from + (rand() % to);
}

char CheckWinner(char Arr_XO[3][3])
{
	// check Row
	for (int i = 0; i < 3; i++)
	{
		if (Arr_XO[i][0] == ' ')
			continue;
		else if (Arr_XO[i][0] == Arr_XO[i][1] && Arr_XO[i][0] == Arr_XO[i][2])
			return Arr_XO[i][0];
	}

	// Check Colume
	for (int i = 0; i < 3; i++)
	{
		// 0 0  1 0   2 0
		// 0 1  1 1   2 1
		// 0 2  1 2	  2 2 
		if (Arr_XO[0][i] == ' ')
			continue;
		else if (Arr_XO[0][i] == Arr_XO[1][i] && Arr_XO[0][i] == Arr_XO[2][i])
			return Arr_XO[i][0];
	}

	// Check Dagnlo
	if (Arr_XO[0][0] != ' ')
	{
		if (Arr_XO[0][0] == Arr_XO[1][1] && Arr_XO[0][0] == Arr_XO[2][2])
			return Arr_XO[0][0];
	}

	if (Arr_XO[0][2] != ' ')
	{
		if (Arr_XO[0][2] == Arr_XO[1][1] && Arr_XO[0][2] == Arr_XO[2][0])
			return Arr_XO[0][0];
	}

	return ' ';
}

void Initialization(char Arr_XO[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Arr_XO[i][j] = ' ';
		}
	}
}

void DrawGame(char Arr_XO[3][3])
{
	int X = 0, Y = 0;
	cout << "------------------------------------------\n";

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i % 2 == 0)
			{
				if (j == 2)
					cout << "~~~~~";
				else if (j < 3)
					cout << "~~~~";
			}
			else
			{
				if (j != 3)
				{
					cout << "# " << Arr_XO[X][Y] << " ";
					Y++;
					if (Y == 3)
					{
						X++;
						Y = 0;
					}
				}
				else
					cout << "#";
			}
		}
		cout << endl;
	}
	cout << "------------------------------------------\n";

}

void ReadFromUser(char Arr_XO[3][3])
{
	int R, C;
	do
	{
		cout << "Enter Number Of Row 1 to 3: ";
		cin >> R;
		cout << "Enter Number Of Column 1 to 3: ";
		cin >> C;

		R--;
		C--;
	} while (Arr_XO[R][C] != ' ' || R < 0 || R > 2 || C < 0 || C > 2);
	cout << "------------------------------------------\n";
	cout << "Your Choise : \n";
	Arr_XO[R][C] = 'X';
}

void ComputerChoise(char Arr_XO[3][3])
{
	int R, C;
	do
	{
		R = RandomNumber();
		C = RandomNumber();

	} while (Arr_XO[R][C] != ' ');
	cout << "------------------------------------------\n";
	cout << "Computer Choise : \n";
	Arr_XO[R][C] = 'O';
}

void Winner(char W)
{
	if (W == 'X')
	{
		system("Color 20");

		cout << "\n\n## You Are Winner. ##\a\a" << endl;
	}
	else if (W == 'O')
	{
		system("Color 40");

		cout << "\n\n###  Game Over, Computer Winer, . ##" << endl;
	}
}

void ClearSystem()
{
	system("Color a");

	system("CLS");
}

void StartGame(char Arr_XO[3][3])
{
	char PlayAgain = 'Y';
	do
	{
		ClearSystem();
		int Counter = 9;

		Initialization(Arr_XO);
		Print();
		DrawGame(Arr_XO);

		while (Counter)
		{
			if (CheckWinner(Arr_XO) != ' ')
			{
				Winner(CheckWinner(Arr_XO));
				break;
			}

			ReadFromUser(Arr_XO);
			DrawGame(Arr_XO);
			Counter--;

			if (Counter == 0)
				break;

			if (CheckWinner(Arr_XO) != ' ')
			{
				Winner(CheckWinner(Arr_XO));
				break;
			}

			ComputerChoise(Arr_XO);
			DrawGame(Arr_XO);
			Counter--;


		}

		if (Counter <= 0)
			cout << "\nGame Over, No Winner . \n\n";

		cout << "You Want Play Again ? Y\N? : ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand(time(NULL));
	char Arr_XO[3][3];
	StartGame(Arr_XO);
};