#include <iostream>
using namespace std;
// Pattern Pyramind
/*
Right Half Pyramind:
*
**
***
****
*****
******

Left Half Pyramind:
		*
	   **
	  ***
	 ****
	*****
   ******
  *******
 ********
*********
Full Pyramind:
	*
   * *
  * * *
 * * * *
* * * * *

inverted Full Pyramind:
 * * * * *
  * * * *
   * * *
	* *
	 *


*/
int ReadHight(string Msg)
{
	int n;
	do
	{
		cout << Msg;
		cin >> n;
	} while (n < 5 || n > 100);
	return n;
}
void Right_Half_Pyramind()
{
	int n = ReadHight("Please Enter Number Betwen 5 To 100 : ");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "---------------------------------------- \n \n";
}
void Left_Half_Pyramind()
{
	int n = ReadHight("Please Enter Number Betwen 5 To 100 : ");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= (n - i - 1))
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "---------------------------------------- \n \n";
}
void Full_Pyramind()
{
	int n = ReadHight("Please Enter Number Betwen 5 To 100 : ");
	int space = n - 1, star = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < space; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < star; k++)
		{
			cout << "* ";
		}
		cout << endl;
		space--;
		star++;
	}
	cout << "---------------------------------------- \n \n";

}

void inverted_Full_Pyramind()
{
	int n = ReadHight("Please Enter Number Betwen 5 To 100 : ");
	int star = n - 1, space = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < space; j++)
		{
			cout << " ";
		}
		for (int k = 0; k <= star; k++)
		{
			cout << "* ";
		}
		cout << endl;
		star--;
		space++;
	}
	cout << "---------------------------------------- \n \n";


}
void Empty_Full_Pyramind()
{
	int n = ReadHight("Please Enter Number Betwen 5 To 100 : ");
	int space = n - 1, star = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < space; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < star; k++)
		{
			if (k == 0 || k == star - 1 || i == 0 || i == n - 1)
				cout << "* ";
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
		space--;
		star++;
	}
	cout << "---------------------------------------- \n \n";

}

int main()
{
	//Right_Half_Pyramind();
	//Left_Half_Pyramind();
	//inverted_Full_Pyramind();
	//Full_Pyramind();
	Empty_Full_Pyramind();
	return 1;
}
