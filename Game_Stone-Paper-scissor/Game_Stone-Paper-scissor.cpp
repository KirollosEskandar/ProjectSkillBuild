#include <iostream>;
#include <vector>;
#include <string>
using namespace std;


/*
	write a small game Program for Stne-Paper-scissor

	- Ask for how many round the game will be.
	- start each round Player vs 'computer
	- show the results with each round.
	- if computer wins the round ring a bill, and
	acreed red
	- if player won the round show green screen
	- after all rounds show game over the print game
	results, then ask the user if he want to play again

*/

int CountWinPLayer = 0, CountWinComputer = 0;

int ReadHowManyRounds()
{
	int n;
	do
	{
		cout << "How Many Rounds 1 to 10 : ";
		cin >> n;
		cout << endl << endl;
	} while (n < 1 || n > 10);
	return n;
}

enum Choise_Paper_St_Sc
{
	Stone = 1,
	Paper = 2,
	Scissor = 3
};

Choise_Paper_St_Sc ChoisePlayer()
{
	int n;
	cout << "Your Choice : [1]:Stone, [2]:Paper, [3]:Scissors ? ";
	cin >> n;
	cout << endl << endl;
	return Choise_Paper_St_Sc(n);
}

Choise_Paper_St_Sc RandamChoiseComp()
{
	int n = rand() % (3) + 1;
	return Choise_Paper_St_Sc(n);
}

string Name(Choise_Paper_St_Sc N)
{
	switch (N)
	{
	case Choise_Paper_St_Sc::Stone:
		return "Stone";
		break;
	case Choise_Paper_St_Sc::Paper:
		return "Paper";
		break;
	case Choise_Paper_St_Sc::Scissor:
		return "Scissor";
		break;
	default:
		break;
	}
	return"";
}
void WhoWin(Choise_Paper_St_Sc Cop, Choise_Paper_St_Sc Pl)
{

	cout << "Player Choise : " << Name(Pl) << endl;
	cout << "Computer Choise : " << Name(Cop) << endl;
	if (Cop == Pl)
	{
		cout << "Round Winner : [No Win]\n";
	}
	else if (Pl == 2 && Cop == 1)
	{
		system("color 2f");
		cout << "\a";
		CountWinPLayer++;
		cout << "Round Winner : [Player]\n";
	}
	else if (Pl == 1 && Cop == 3)
	{
		system("color 2f");
		cout << "\a";
		CountWinPLayer++;
		cout << "Round Winner : [Player]\n";
	}
	else if (Pl == 3 && Cop == 2)
	{
		system("color 2f");
		cout << "\a";
		CountWinPLayer++;
		cout << "Round Winner : [Player]\n";
	}
	else
	{
		system("color 4f");
		CountWinComputer++;
		cout << "Round Winner : [Computer]\n";
	}
}

void RoundYouChoice(int Round)
{
	for (int i = 1; i <= Round; i++)
	{
		cout << "____ Round[" << i << "] _____\n\n";
		WhoWin(RandamChoiseComp(), ChoisePlayer());
		cout << "_______________________________\n\n\n";
	}
}

void GameOver(int Round)
{
	int Draw = (Round - (CountWinComputer + CountWinPLayer));
	string finalWin;
	finalWin = CountWinComputer > CountWinPLayer ? "ComPuter" : "Player";
	cout << "\t\t\t-----------------------------------------------\n\n";
	cout << "\t\t\t\t\t+++ G a m e    O v e r +++\n";
	cout << "\t\t\t-----------------------------------------------\n\n";

	cout << "\t\t\t----------[Game Results]------------------------\n\n";
	cout << "\t\t\tGame Rounds        :" << Round << endl;
	cout << "\t\t\tPlayer Win Times   :" << CountWinPLayer << endl;
	cout << "\t\t\tComPuter Win Times :" << CountWinComputer << endl;
	cout << "\t\t\tDraw Times         :" << Draw << endl;
	cout << "\t\t\tFinal Winner       :"
		<< (CountWinComputer == CountWinPLayer ? "Not Winnter" : finalWin) << endl;
	cout << "\t\t\t-----------------------------------------------\n\n";





}
void PlayAgain()
{
	char YN;
	do
	{
		cout << "\t\t\t\Do you want to play again? Y/N?";
		cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			system("CLS");
			int HowMany = ReadHowManyRounds();
			RoundYouChoice(HowMany);
			GameOver(HowMany);
		}

	} while (YN == 'Y' || YN == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	int HowMany = ReadHowManyRounds();
	RoundYouChoice(HowMany);
	GameOver(HowMany);
	PlayAgain();
}