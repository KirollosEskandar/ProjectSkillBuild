#include <iostream>;
#include <vector>;
#include <string>;
#include <fstream>;
using namespace std;

struct sClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
    bool MarkForDelete = false;


};

const string ClientsFileName = "Clients.txt";
sClient CurrentClient;
void Login();
void GoBackToAtmMainMenue();

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}
void SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }


}

// Check Balance
void CheckBalanceScreen()
{
    cout << "\n---------------------------------------\n";
    cout << "\t\t Check Balance Screen .\n";
    cout << "---------------------------------------\n";

    cout << "Your Balance is : " << CurrentClient.AccountBalance << endl;

}

// Deposit.
void UpdateBalance()
{
    vector <sClient> Clients = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient& Cl : Clients)
    {
        if (Cl.AccountNumber == CurrentClient.AccountNumber)
        {
            Cl = CurrentClient;
            break;
        }
    }

    SaveCleintsDataToFile(ClientsFileName, Clients);

}
void Deposit()
{
    float Dep;

    do
    {
        cout << "Enter positive balance for deposit : ";
        cin >> Dep;

    } while (Dep < 1);

    CurrentClient.AccountBalance += Dep;
}
void DepositScreen()
{
    cout << "\n---------------------------------------\n";
    cout << "\t\t Deposit Screen .\n";
    cout << "---------------------------------------\n";

    Deposit();
    UpdateBalance();
    cout << "Deposit successfull, Your Balance is : " << CurrentClient.AccountBalance << endl;

}

// Normal Withdrawal.
// Enter the amount in multiples of 5:
void NormalWithdrawal()
{
    int Dep;

    do
    {
        cout << "Enter the amount in multiples of 5: ";
        cin >> Dep;

        if (Dep > CurrentClient.AccountBalance)
        {
            cout << "\nAmount to be withdrawn is greater than your balance." << endl;
            cout << "\nYour Balance is : " << CurrentClient.AccountBalance << endl;


            cout << "\nEnter the amount in multiples of 5:";
            cin >> Dep;
        }


    } while ((Dep % 5) != 0);

    CurrentClient.AccountBalance -= Dep;
}

void NormalWithdrawalScreen()
{
    cout << "\n---------------------------------------\n";
    cout << "\t\t Normal Withdrawal Screen .\n";
    cout << "---------------------------------------\n";

    NormalWithdrawal();
    UpdateBalance();
    cout << "Withdrawal successfull, Your Balance is : " << CurrentClient.AccountBalance << endl;

}

// Quick Withdraw.
enum eQuicWithDraw
{
    eQuicWithdrawl_50 = 1,
    eQuicWithdrawl_200 = 2,
    eQuicWithdrawl_500 = 3,
    eQuicWithdrawl_1000 = 4,
    eQuicWithdrawl_5000 = 5,
    eExut = 6
};

int ConverQuickChoise(eQuicWithDraw Q)
{
    switch (Q)
    {
    case eQuicWithdrawl_50:
        return 50;
    case eQuicWithdrawl_200:
        return 200;
    case eQuicWithdrawl_500:
        return 500;
    case eQuicWithdrawl_1000:
        return 1000;
    case eQuicWithdrawl_5000:
        return 5000;
    case eExut:
        break;
    }
    return 0;
}
void QuickWithdrawal()
{
    short Q;
    do
    {
        cout << "Enter Your Choise From 1 to 6 : ";
        cin >> Q;
        if (ConverQuickChoise(eQuicWithDraw(Q)) > CurrentClient.AccountBalance)
        {
            cout << "\nAmount to be withdrawn is greater than your balance." << endl;
            cout << "\nYour Balance is : " << CurrentClient.AccountBalance << endl;

            cout << "Enter Your Choise From 1 to 6 : ";
            cin >> Q;
        }

    } while (Q < 1 || Q > 5);

    CurrentClient.AccountBalance -= ConverQuickChoise(eQuicWithDraw(Q));
}
void QuickWithdrawalScreen()
{
    cout << "\n---------------------------------------\n";
    cout << "\t\t Quick Withdrawal Screen .\n";
    cout << "---------------------------------------\n";
    cout << "\t [1] 50 \t  [2] 200" << endl;
    cout << "\t [3] 500 \t  [4] 1000" << endl;
    cout << "\t [5] 5000 \t  [6] Exit " << endl;
    cout << "---------------------------------------\n";
    cout << "Your Balance is : " << CurrentClient.AccountBalance << endl;
    cout << "---------------------------------------\n";

    QuickWithdrawal();
    UpdateBalance();
    cout << "Withdrawal successfull, Your Balance is : " << CurrentClient.AccountBalance << endl;

}


// Atm Main
enum eAtmChoiseOption
{
    eQuickWithdraw = 1,
    eNormalWithdrawal = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5
};
short ReadChoiseAtm()
{
    int n;
    cout << "Choise What do you Want To Do {1 To 5} ? : ";
    cin >> n;
    return n;
}
void ActionAtmChoise(eAtmChoiseOption AtmChoiseOption)
{
    switch (AtmChoiseOption)
    {
    case eQuickWithdraw:
        system("CLS");
        QuickWithdrawalScreen();
        GoBackToAtmMainMenue();
        break;
    case eNormalWithdrawal:
        system("CLS");
        NormalWithdrawalScreen();
        GoBackToAtmMainMenue();
        break;
    case eDeposit:
        system("CLS");
        DepositScreen();
        GoBackToAtmMainMenue();
        break;
    case eCheckBalance:
        system("CLS");
        CheckBalanceScreen();
        GoBackToAtmMainMenue();
        break;
    case eLogout:
        system("CLS");
        Login();
        GoBackToAtmMainMenue();
        break;
    default:
        break;
    }
}
void ShowAtmMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tAtm Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdrawal.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    ActionAtmChoise((eAtmChoiseOption)ReadChoiseAtm());
}

void GoBackToAtmMainMenue()
{
    cout << "Press any Key To Back To Atm Main ...";
    system("pause>0");
    ShowAtmMainMenue();
}
// LOsgin
void LoginScreen()
{
    cout << "\n---------------------------------------\n";
    cout << "\t\t Login Screen .\n";
    cout << "---------------------------------------\n";


}

bool IsCoreectLogin(sClient& Client)
{
    vector <sClient> Clients = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient Cl : Clients)
    {
        if (Cl.AccountNumber == Client.AccountNumber && Cl.PinCode == Client.PinCode)
        {
            Client = Cl;
            return true;
        }
    }

    return false;
}
sClient ReadLoginClient()
{
    sClient Client;

    cout << "Please Enter Account Number : ";
    cin >> Client.AccountNumber;

    cout << "Please Enter PIn : ";
    cin >> Client.PinCode;

    return Client;
}
void Login()
{
    LoginScreen();
    sClient LoginClient = ReadLoginClient();

    while (!IsCoreectLogin(LoginClient))
    {
        system("CLS");
        LoginScreen();

        cout << "Incorrect PinCode or Account number." << endl;
        LoginClient = ReadLoginClient();
    }

    CurrentClient = LoginClient;
    ShowAtmMainMenue();

}


int main()
{
    Login();
}