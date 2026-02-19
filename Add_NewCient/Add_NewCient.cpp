// Add_NewCient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsPerson.h"
using namespace std;
void ReadClientInfo(clsBankClient& Client) {
    cout << "\nEnter FirstName: ";
    Client.FirstName = clsInputValidate::ReadString();
    cout << "\nEnter Last Name: ";
    Client.LastName = clsInputValidate::ReadString();
    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();
    cout << "\nEnter Phone Number: ";

    Client.Phone = clsInputValidate::ReadString();
    cout << "\nEnter Pin Code: ";
    Client.PinCode = clsInputValidate::ReadString();
    cout << "\nEnter ACC Balance: ";
    Client.setAccountBalance(clsInputValidate::ReadDoubleNumber());




}
void AddNewClient() {
    string AccountNumber;
    cout << "\nPlease Enter Account NUmber?\n";
    AccountNumber= clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber)) {

        cout << "\nAccount Number Is Already Used,Choose Another One: ";
        AccountNumber = clsInputValidate::ReadString();

    }
    clsBankClient AClient = clsBankClient::GetAddNewClient(AccountNumber);
    ReadClientInfo(AClient);
    clsBankClient::enSaveResult svResult = AClient.Save();
    switch (svResult) {
    case clsBankClient::enFaildSave:
        cout << "\nThe Account Number Is Not Found";
        break;
    case clsBankClient::svFaildAccountNumber:
        cout << "\nThe Account Number Is Not Found";
        break;
    case clsBankClient::enSuccessSave:
        cout << "\n__________________________\n";
        cout << "Updated Successed \n";
        cout << "_____________________________\n";
        AClient.Print();
        break;


    }

}
int main()
{
    AddNewClient();

    system("pause>0");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
