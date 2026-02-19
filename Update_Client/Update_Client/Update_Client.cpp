// Update_Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsPerson.h"
using namespace std;
void ReadClientInfo(clsBankClient& Client) {
    cout << "\nEnter FirstName: ";
    Client.FirstName= clsInputValidate::ReadString();
    cout << "\nEnter LastName: ";
    Client.LastName = clsInputValidate::ReadString();
    cout << "\nEnter pincode: ";
    Client.PinCode = clsInputValidate::ReadString();
    cout << "\nEnter email: ";
    Client.Email = clsInputValidate::ReadString();
   ///* cout << "\nenter passward: ";*/
   // Client.PinCode= clsInputValidate::ReadString();
    cout << "\nenter phone: ";
    Client.Phone = clsInputValidate::ReadString();
    Client.AccountBalance = clsInputValidate::ReadDoubleNumber("\n enter balance: ");


}

void UpdateClient() {
    string AccountNumber;
    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "\nAccoun Number Is Not Found,Choose anothe one: ";

        AccountNumber = clsInputValidate::ReadString();

    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();
    cout << "\n\nUpdate Client Info\n";
    cout << "\n__________________________________\n";

    ReadClientInfo(Client);
    clsBankClient::enSaveResult enResult= Client.Save();
    switch (enResult){
    case clsBankClient::enFaildSave:
        cout << "\nThe Filed Not Found ";
        break;
   
    case clsBankClient::enSuccessSave:
        cout << "\nSuccessed File Is Found \n";
        Client.Print();
    }
    
}
int main()
{
    UpdateClient();


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
