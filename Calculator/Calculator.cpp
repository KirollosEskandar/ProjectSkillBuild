#include <iostream>
using namespace std;
// Calculator
/*


*/
char Print()
{
	cout << "Hello This Sample Calc, Now Tell You What You Can Do By This Calc : " << endl;
	char c;
	do
	{
		cout << "Please Only Enter To ( - Or + Or * Or / ): " << endl;
		cin >> c;

	} while (c != '-' && c != '+' && c != '*' && c != '/');
	return c;
}
float ReadNumber(string Msg)
{
	float Number;
	do
	{
		cout << Msg;
		cin >> Number;
	} while (Number < 1);
	return Number;
}
float SimpleCalculator(char Op)
{
	float Num1 = ReadNumber("Please Enter A First Number : "), Num2;
	Num2 = ReadNumber("Please Enter A Secound Number : ");

	switch (Op)
	{
	case '-':
		return Num1 - Num2;
	case '+':
		return Num1 + Num2;
	case '*':
		return Num1 * Num2;
	case '/':
		return Num1 / Num2;
	default:
		return 0;
	}
}
int main()
{
	char c = Print();
	cout << "Reslut : " << SimpleCalculator(c) << endl;
	return 1;
}
