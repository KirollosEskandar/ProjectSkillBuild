#include <iostream>;
#include <string>;
#include <vector>;
#include <fstream>;
#include <iomanip>;
using namespace std;

const string FileName = "Clients.txt";
struct SClient
{
	string AccountNumber;
	string PinCod;
	string Name;
	string Phone;
	double AccountBalance = 0;
};
bool FindClientByAccountNumber(SClient& Clint, string AccountNumber);

SClient ReadClient()
{
	SClient Client;
	cout << "Enter Account Number : ";
	getline(cin >> ws, Client.AccountNumber);
	while (FindClientByAccountNumber(Client, Client.AccountNumber))
	{
		cout << "\nClient With [" << Client.AccountNumber << "] already exists \n";

		cout << "Enter another Account Number : ";
		getline(cin >> ws, Client.AccountNumber);
	}
	cout << "Enter Pine Code : ";
	getline(cin, Client.PinCod);

	cout << "Enter Name : ";
	getline(cin, Client.Name);

	cout << "Enter Phone : ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance : ";
	cin >> Client.AccountBalance;

	return Client;
}

string RecordLine(SClient Client, string sap = "#//#")
{
	string recLine;

	recLine = Client.AccountNumber + sap;
	recLine += Client.PinCod + sap;
	recLine += Client.Name + sap;
	recLine += Client.Phone + sap;
	recLine += to_string(Client.AccountBalance);

	return recLine;
}

void AddClientToFile(string client, string NameFile)
{
	fstream Myfile;
	Myfile.open(NameFile, ios::app | ::ios::out);

	if (Myfile.is_open())
	{
		Myfile << client << endl;
		Myfile.close();
	}
}
void ShowMainMinueScreen()
{
	cout << "=============================================\n";
	cout << "\t\tMain Minue Screen\n";
	cout << "=============================================\n";
	cout << "\t[1] Add New Client.\n";
	cout << "\t[2] Delete Client.\n";
	cout << "\t[3] Update Client.\n";
	cout << "\t[4] Find Client.\n";
	cout << "\t[5] Show Client list.\n";
	cout << "\t[6] Exsit.\n";
	cout << "=============================================\n";

}

vector<string> SplitString(string line, string sap = "#//#")
{
	int pos;
	string Word;
	vector<string> client;
	while ((pos = line.find(sap)) != std::string::npos)
	{
		Word = line.substr(0, pos);

		if (Word != "")
			client.push_back(Word);

		line.erase(0, pos + sap.size());
	}


	if (line != "")
		client.push_back(line);

	return client;
}
SClient AddSt_Clien(vector<string> Vclient)
{
	SClient Client;

	Client.AccountNumber = Vclient[0];
	Client.PinCod = Vclient[1];
	Client.Name = Vclient[2];
	Client.Phone = Vclient[3];
	Client.AccountBalance = stod(Vclient[4]);
	return Client;
}
vector <SClient> ReadClientFromFile(string NameFile)
{
	fstream Myfile;
	vector<string> Spli;
	vector< SClient> Clients;
	Myfile.open(NameFile, ios::in);

	if (Myfile.is_open())
	{
		string line;
		while (getline(Myfile, line))
		{
			Spli = SplitString(line);
			Clients.push_back(AddSt_Clien(Spli));
		}
	}

	return Clients;
}


bool FindClientByAccountNumber(SClient& Clint, string AccountNumber)
{
	vector <SClient> Clients = ReadClientFromFile(FileName);


	for (SClient Clnt : Clients)
	{
		if (Clnt.AccountNumber == AccountNumber)
		{
			Clint = Clnt;
			return true;
		}
	}
	return false;
}
void PrintClient(SClient client)
{
	cout << "Account Number : " << client.AccountNumber << endl;
	cout << "Pin Code       : " << client.PinCod << endl;
	cout << "Name           : " << client.Name << endl;
	cout << "Phone          : " << client.Phone << endl;
	cout << "Balanc         : " << client.AccountBalance << endl;
}


void ShowFindAccountSecreen()
{
	system("cls");
	cout << "____________________________________________" << endl;
	cout << "\t\t Find Client Scren. \n";
	cout << "____________________________________________" << endl;

	string An;
	SClient Clnt;
	cout << "Please Enter AccountNumber : ";
	cin >> An;

	if (FindClientByAccountNumber(Clnt, An))
	{
		cout << "The Following are Account : \n" << endl;
		PrintClient(Clnt);
	}
	else
	{
		cout << "Client Wit Account{" << An << "] is No Fount";
	}
}

void ShowClientsLast(string NameFile)
{
	system("cls");
	vector<SClient> Clients = ReadClientFromFile(NameFile);

	cout << endl << setw(50) << "Client List (" << Clients.size() << ") Client(s).\n";
	cout << "_______________________________________________________________________________________________________\n\n";
	cout << left << setw(25) << "| Account Number";
	cout << left << setw(15) << "| Pin Code";
	cout << left << setw(30) << "| Client Name";
	cout << left << setw(15) << "| Phone";
	cout << left << setw(15) << "| Balance\n";
	cout << "\n_______________________________________________________________________________________________________\n\n";


	///

	for (SClient Clnt : Clients)
	{
		cout << left << "| " << setw(23) << Clnt.AccountNumber;
		cout << left << "| " << setw(12) << Clnt.PinCod;
		cout << left << "| " << setw(28) << Clnt.Name;
		cout << left << "| " << setw(13) << Clnt.Phone;
		cout << left << "| " << setw(13) << Clnt.AccountBalance << endl;
	}
	cout << "\n_______________________________________________________________________________________________________\n";

}


// Detete 
vector <SClient> DeleteClientByAccountNumber(string AccountNumber)
{
	vector <SClient> Clients = ReadClientFromFile(FileName);


	for (int i = 0; i < Clients.size(); i++)
	{
		if (Clients[i].AccountNumber == AccountNumber)
		{
			Clients.erase(Clients.begin() + i);
		}
	}
	return Clients;
}
void UpdataFile(vector <SClient> Vf, string FileName)
{
	fstream Myfile;
	Myfile.open(FileName, ios::out);

	if (Myfile.is_open())
	{
		for (SClient Clnt : Vf)
		{
			Myfile << RecordLine(Clnt) << endl;
		}

		Myfile.close();
	}

}
void DeleteFindAccountSecreen()
{
	system("cls");
	cout << "____________________________________________" << endl;
	cout << "\t\t Delete Client Scren. \n";
	cout << "____________________________________________" << endl;

	string An;
	SClient Clnt;
	cout << "Please Enter AccountNumber : ";
	cin >> An;

	if (FindClientByAccountNumber(Clnt, An))
	{
		cout << "The Following are Account : \n" << endl;
		PrintClient(Clnt);

		char YN;
		cout << "Are You Want Delete This Client ? Y/N? ";
		cin >> YN;

		if (YN == 'y' || YN == 'Y')
		{
			UpdataFile(DeleteClientByAccountNumber(An), FileName);
			cout << "\nThe client has been deleted successfully \n";
		}
	}
	else
	{
		cout << "Client Wit Account{" << An << "] is No Fount";
	}
}

// Update
void ReadClient(SClient& Client)
{
	cout << "Enter Pine Code : ";
	getline(cin >> ws, Client.PinCod);

	cout << "Enter Name : ";
	getline(cin, Client.Name);

	cout << "Enter Phone : ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance : ";
	cin >> Client.AccountBalance;

}
vector <SClient> UpdataClientByAccountNumber(string AccountNumber)
{
	vector <SClient> Clients = ReadClientFromFile(FileName);


	for (int i = 0; i < Clients.size(); i++)
	{
		if (Clients[i].AccountNumber == AccountNumber)
		{
			ReadClient(Clients[i]);
		}
	}
	return Clients;
}
void UpdataFindAccountSecreen()
{
	system("cls");
	cout << "____________________________________________" << endl;
	cout << "\t\t Updata Client Scren. \n";
	cout << "____________________________________________" << endl;

	string An;
	SClient Clnt;
	cout << "Please Enter AccountNumber : ";
	cin >> An;

	if (FindClientByAccountNumber(Clnt, An))
	{
		UpdataFile(UpdataClientByAccountNumber(An), FileName);

		cout << "\nThe client has been Updata successfully\n";
	}
	else
	{
		cout << "Client Wit Account{" << An << "] is No Fount";
	}
}





void AddNewClient()
{
	system("cls");
	cout << "---------------------------------\n";
	cout << "\t Add New Clients Scren.  " << endl;
	cout << "---------------------------------\n";


	SClient client = ReadClient();
	string line = RecordLine(client);
	AddClientToFile(line, FileName);

	cout << "\nThe client has been added successfully \n";
}



int Chose()
{
	int Choise;
	ShowMainMinueScreen();
	cout << "Chose What do you Want to do ? [1 to 6}?";
	cin >> Choise;

	while (Choise < 1 || Choise > 6)
	{
		cout << "No Corect, Please Only Choise [1 to 6] :";
		cin >> Choise;
	}
	return Choise;
}

void StartProgram(string NameFile)
{
	string Minue;

	do
	{
		system("cls");
		switch (Chose())
		{
		case 1:
			AddNewClient();
			break;
		case 2:
			DeleteFindAccountSecreen();
			break;
		case 3:
			UpdataFindAccountSecreen();
			break;
		case 4:
			ShowFindAccountSecreen();
			break;
		case 5:
			ShowClientsLast(NameFile);
			break;
		case 6:
			return;
			break;
		}

		cout << "Enter Any Key To Go back Minue ....";
		cin >> Minue;
	} while (Minue != "No");


}
int main()
{
	StartProgram(FileName);

}
