#include <iostream>;
#include <string>;

using namespace std;


struct Student
{
	int Age;
	string Name;
	float Arbic, Engilish, Math, percentage;
};

void PrintTital()
{
	cout << "Enter choice:\n1  - to add a new student" << endl
		<< "2  - to show all students" << endl
		<< "3  - to calculate and print percentage per student" << endl
		<< "4  - to get the student with highest percentage" << endl
		<< "5  - to get average percentage" << endl
		<< "-1 - to end the application" << endl;


}

void PrintStudent(Student St)
{
	cout << "\n-------------------------\n";

	cout << "Name : " << St.Name << endl;
	cout << "Age : " << St.Age << endl;
	cout << "Arbic : " << St.Arbic << endl;
	cout << "Engilish : " << St.Engilish << endl;
	cout << "Math : " << St.Math << endl;
	cout << "Percentage is : " << St.percentage << "%" << endl;

	cout << "\n-------------------------\n";
}



void ShowAllStendent(Student* St, int Count)
{
	for (int i = 0; i < Count; i++)
	{
		PrintStudent(St[i]);
	}
}
// print percentage per student
void ShowAllPercentagePerStudent(Student* St, int Count)
{
	for (int i = 0; i < Count; i++)
	{
		cout << "\n-------------------------\n";

		cout << "Name : " << St[i].Name << endl;
		cout << "Age : " << St[i].Age << endl;
		cout << "Percentage is : " << St[i].percentage << "%" << endl;


		cout << "\n-------------------------\n";
	}
}

// highest percentage
void GetHighestPercentage(Student* St, int index)
{
	Student Studnt;
	int n = 0;

	for (int i = 0; i < index; i++)
	{
		if (St[i].percentage > n)
		{
			n = St[i].percentage;
			Studnt = St[i];
		}
	}

	cout << "\n\n\Highest Percentage : \n";
	PrintStudent(Studnt);
}

void AddNewStudent(Student* St, int index)
{
	cout << "\n-------------------------\n";
	cout << "Enter Name : ";
	getline(cin >> ws, St[index].Name);

	cout << "Enter Age : ";
	cin >> St[index].Age;

	cout << "Enter Grade Arbic : ";
	cin >> St[index].Arbic;

	cout << "Enter Grade Math : ";
	cin >> St[index].Math;

	cout << "Enter Grade Engilish : ";
	cin >> St[index].Engilish;

	St[index].percentage = ((St[index].Engilish + St[index].Arbic + St[index].Math) / 300) * 100;
	cout << "\n-------------------------\n";

}

// average percentage

// average percentage
int AvgPercentageAllStuden(Student* st, int Count)
{
	float Avg = 0;

	for (int i = 0; i < Count; i++)
	{
		Avg += st[i].percentage;
	}
	Avg /= (Count * 100);
	Avg *= 100;

	return Avg;
}
void Start(Student* St, int Count)
{
	PrintTital();
	int Choise = -1, index = 0;
	do
	{
		//system("CLS");
		cout << "What is your choice : ";
		cin >> Choise;

		switch (Choise)
		{
		case 1:
			if (index == Count)
			{
				cout << "\n--------------------------------\n";
				cout << "There is no space to add students." << endl;
				cout << "\n--------------------------------\n";

			}
			else
			{
				AddNewStudent(St, index);
				index++;
			}
			break;
		case 2:
			ShowAllStendent(St, index);
			break;
		case 3:
			ShowAllPercentagePerStudent(St, index);
			break;
		case 4:
			GetHighestPercentage(St, index);
			break;
		case 5:
			cout << "\nAverage Percentage : " << AvgPercentageAllStuden(St, index) << "%" << endl;;
			break;
		}


	} while (Choise != -1);
}
int main()
{
	int Count;
	cout << "How Many You Have Students ? ";
	cin >> Count;

	Student* Students = new Student[Count];

	Start(Students, Count);

	delete[]Students;
}