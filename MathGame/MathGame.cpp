#include <iostream>;
#include <vector>;
#include <string>
using namespace std;


enum TypeDifficulty { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum TypeCalculate { Add = 1, Sub = 2, Mul = 3, Div = 4, Mixx = 5 };
struct FinalResults
{
	int QuestionOfNum = 0;
	TypeDifficulty TDifficulty;
	TypeCalculate TCalculate;
	int RightAnswer = 0, WrongAnswer = 0;

};


int RandomNumber(int from = 1, int to = 5)
{
	int r = from + (rand() % to);

	return r;
}

int ReadHowMany()
{
	int n;
	do
	{
		cout << "How Many Questions You want to answer ? ";
		cin >> n;
	} while (n < 0);
	return n;
}

TypeDifficulty ChoiceDifficulty()
{
	int n;
	cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
	cin >> n;
	cout << endl;
	return TypeDifficulty(n);
}
TypeCalculate ChoiceCalculate()
{
	int n;
	cout << "Enter Questions Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
	cin >> n;
	cout << endl;
	return TypeCalculate(n);
}

int WhatDifficulty(TypeDifficulty TypeDiff)
{
	switch (TypeDiff)
	{
	case TypeDifficulty::Easy:
		return RandomNumber(1, 20);
		break;
	case TypeDifficulty::Med:
		return RandomNumber(20, 70);
		break;
	case TypeDifficulty::Hard:
		return RandomNumber(50, 99);
		break;
	case TypeDifficulty::Mix:
		return WhatDifficulty(TypeDifficulty(RandomNumber(1, 3)));
		break;
	default:
		break;
	}
	//return -1;
}


int Calculate(TypeDifficulty TDiff, TypeCalculate Type)
{
	int a = WhatDifficulty(TDiff), b = WhatDifficulty(TDiff), r = 0;
	switch (Type)
	{
	case TypeCalculate::Add:
		cout << a << endl << b << " +\n";
		return  a + b;
		break;
	case TypeCalculate::Sub:
		cout << a << endl << b << " -\n";
		return  a - b;
		break;
	case TypeCalculate::Mul:
		cout << a << endl << b << " *\n";
		return  a * b;
		break;
	case TypeCalculate::Div:
		cout << a << endl << b << " /\n";
		return  a / b;
		break;
	case TypeCalculate::Mixx:
		return Calculate(TDiff, TypeCalculate(RandomNumber(1, 4)));
		break;
	default:
		break;
	}
	return r;
}


int UserAnswer()
{
	int n;
	cout << "------------------\n";
	cin >> n;
	cout << endl;
	return n;
}

void PrintCheckAnswer(bool Chk, int n)
{
	if (Chk)
	{
		cout << "Right Answer:-)." << endl;
		cout << "\a";
		system("color 2f");
	}
	else
	{
		cout << "Worng Answer :-(\n";
		cout << "The right answer is : " << n << endl;
		system("color 4f");
	}
}
bool ChekAnswer(TypeDifficulty TDiff, TypeCalculate Type)
{
	int Calc = Calculate(TDiff, Type);
	if (Calc == UserAnswer())
	{
		PrintCheckAnswer(true, Calc);
		return true;
	}
	else
	{
		PrintCheckAnswer(false, Calc);
		return false;
	}
}

void RestScreen()
{
	system("CLS");
	system("color 0f");
}





string GetNameTypeDifficulty(int ind)
{
	// enum TypeDifficulty { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
	string T[4] = { "Easy", "Med", "Hard", "Mix" };
	return T[ind - 1];
}

string GetNameTypeCalculate(int ind)
{
	// enum TypeCalculate { Add = 1, Sub = 2, Mul = 3, Div = 4, Mixx = 5};
	string T[5] = { "Add", "Sub", "Mul", "Div", "Mix" };
	return T[ind - 1];
}

void ShowFinalResults_Pass_Fail(int right, int wrong)
{
	cout << endl << endl;
	cout << "_______________________________" << endl;
	cout << "Final Results is ";
	if (right < wrong)
	{
		system("color 4f");
		cout << "Fail" << endl;
	}
	else
	{
		system("color 2f");
		cout << "\a\a";
		cout << "Pass" << endl;
	}

}
void ShowFinalResults(FinalResults Finall)
{
	ShowFinalResults_Pass_Fail(Finall.RightAnswer, Finall.WrongAnswer);
	cout << "_______________________________" << endl;
	cout << "Number of Questions : " << Finall.QuestionOfNum << endl;
	cout << "Questions Level     : " << GetNameTypeDifficulty(Finall.TDifficulty) << endl;
	cout << "OP Type             : " << GetNameTypeCalculate(Finall.TCalculate) << endl;
	cout << "Numbers Of Right Answers: " << Finall.RightAnswer << endl;
	cout << "Numbers Of Wrong Answers: " << Finall.WrongAnswer << endl;
	cout << "_______________________________" << endl;
}

void FillDataRound(bool Right, FinalResults& F_Res)
{
	if (Right == true)
		F_Res.RightAnswer++;
	else if (Right == false)
		F_Res.WrongAnswer++;
}

FinalResults QuestionRound(int HowMany, TypeDifficulty TDiff, TypeCalculate Type)
{
	FinalResults F_Res;
	bool Chk;
	for (int i = 1; i <= HowMany; i++)
	{
		cout << "\n\nQuestion [" << i << "/" << HowMany << "]" << endl;
		Chk = ChekAnswer(TDiff, Type);
		FillDataRound(Chk, F_Res);
	}
	return F_Res;
}
void StartGame()
{
	char AgainGame = 'Y';
	FinalResults Finall;
	Finall.RightAnswer = Finall.WrongAnswer = 0;

	do
	{
		RestScreen();
		int n = ReadHowMany();
		TypeDifficulty Td = ChoiceDifficulty();
		TypeCalculate Tc = ChoiceCalculate();
		Finall = QuestionRound(n, Td, Tc);
		//Fill Round Data
		Finall.QuestionOfNum = n;
		Finall.TCalculate = Tc;
		Finall.TDifficulty = Td;
		ShowFinalResults(Finall);
		cout << "Do You Want to play agian? Y/N?";
		cin >> AgainGame;

	} while (AgainGame == 'Y' || AgainGame == 'y');
}


int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}