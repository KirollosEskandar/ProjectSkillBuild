#include <iostream>;
#include <vector>;
using namespace std;

/*
#Connnect 4
# ☀ ●  ║   ═
✔✘ *@
============================
| * | * | * | * | * | * | * |
============================
| * | * | * | * | * | * | * |
============================
| * | * | * | * | * | * | * |
============================
| * | * | * | * | * | * | * |
============================
| * | * | * | * | * | * | * |
============================
| * | * | * | * | * | * | * |
============================

✔


============================
| - | - | - | @ | - | - | * |
============================
| - | - | @ | - | - | - | * |
============================
| - | @ | * | - | - | - | * |
============================
| @ | @ | @ | @ | - | - | * |
============================

══════════════════
║✘║✘║✘║✘║✘║✘║✘║
 ══════════════════
║✔║✔║✔║✔║✔║✔║✔║
 ══════════════════
║✘║✘║✘║✘║✘║✘║✘║
 ══════════════════
║✔║✔║✔║✔║✔║✔║✔║
 ══════════════════
║✘║✘║✘║✘║✘║✘║✘║
 ══════════════════
║✔║✔║✔║✔║✔║✔║✔║
 ══════════════════



*/

char CheckWinner(char arr[6][7])
{
	// Not Compate : 
	// Check Row if 4 The Same return Winner
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] != ' ')
			{
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
				{
					return arr[i][j];
				}
			}

		}
	}

	/// Check Coulm if 4 The Same Return Winner
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[j][i] != ' ')
			{
				if (arr[j][i] == arr[j + 1][i] && arr[j][i] == arr[j + 2][i] && arr[j][i] == arr[j + 3][i])
				{
					return arr[j][i];
				}
			}

		}
	}

	return ' ';
}

void Print()
{
	cout << "########################################## \n\n";
	cout << "############## Connect 4 #################\n \n";
	cout << "------------------------------------------\n";
	cout << "1 - You Now PLay With Computer .  " << endl;
	cout << "2 - You Player '@'.  " << endl;
	cout << "3 - Computer Player '*'.  " << endl;
	cout << "------------------------------------------\n";
	cout << "\n########################################## \n";
}

int RandamNumber(int from = 0, int to = 6)
{
	return from + (rand() % to);
}

void ReadFromUser(char arr[6][7])
{
	int r, c;
	do
	{
		do
		{
			cout << "Please Enter Row From 1 to 6 : ";
			cin >> r;

			cout << "Please Enter Colum From 1 to 7 : ";
			cin >> c;
			r--;
			c--;

		} while (r < 0 || c < 0 || r > 5 || c > 6);

	} while (arr[r][c] != ' ');

	arr[r][c] = '@';
	cout << "You Done Choise... ! \n";
}

void ComputerChoise(char arr[6][7])
{
	int r, c;
	do
	{

		r = RandamNumber();
		c = RandamNumber(0, 7);

	} while (arr[r][c] != ' ');

	arr[r][c] = '*';
	cout << "Computer Done Choise... ! \n";
}

void Initialization(char arr[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void DrawConnect4(char arr[6][7])
{
	int x = 0, y = 0;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j != 7)
					cout << "====";
			}
			else
			{
				if (j == 7)
					cout << "|";
				else
				{
					if (y == 7)
					{
						y = 0;
						x++;
					}
					cout << "| " << arr[x][y] << " ";
					y++;
				}

			}
		}
		cout << endl;
	}
}


void StartGame()
{
	char arr[6][7];
	Initialization(arr);
	int Contier = 42;
	do
	{
		system("cls");
		Print();

		DrawConnect4(arr);

		ReadFromUser(arr);
		Contier--;
		if (CheckWinner(arr) != ' ')
		{
			cout << "Winner is  " << CheckWinner(arr) << endl;
			break;
		}


		ComputerChoise(arr);
		cout << "\a\a";

		Contier--;
		if (CheckWinner(arr) != ' ')
		{
			cout << "Winner is  " << CheckWinner(arr) << endl;
			break;
		}



	} while (Contier > 0);

	if (Contier <= 0)
		cout << "No Winner \n";
}
int main()
{
	StartGame();

}