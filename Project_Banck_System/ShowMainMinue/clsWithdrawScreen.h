#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;
class clsWithdrawScreen:clsScreen
{
static 	string _ReadAccountNumber() {
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number ? ";

		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;

}
static bool _WithdrawClient(double Ammount,clsBankClient Client) {
	return (Ammount <= Client.AccountBalance && Ammount >=0);

}
static void _PrintClient(clsBankClient Client) {

	cout << "\nClient Card : ";
	cout << "\n__________________________";
	cout << "\nFirst Name     : " << Client.FirstName;
	cout << "\nLast Name      : " << Client.LastName;
	cout << "\nFull Name      : " << Client.FullName();
	cout << "\nEmail          : " << Client.Email;
	cout << "\nPhone          : " << Client.Phone;
	cout << "\nAccNumber      : " << Client.AccountNumber();
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\nPin Code       : " << Client.PinCode;
	cout << "\n__________________________\n";


}
public:
	static void ShowWithDrawScreen() {
		clsScreen::_DrawScreenHeader("Withdraw Screen");
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nThe Account Number Is Not Found ";
			AccountNumber = _ReadAccountNumber();


		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		cout << "\n===================================\n";

		double Ammount;
		cout << "\nPlease Enter Withdraw Ammount? ";
		Ammount = clsInputValidate::ReadDoubleNumber();



		cout << "\nAre You Sure you want to perform this transactions? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {

			if (!Client1.WithDraw(Ammount)) {


				cout << "\nCannot withdraw, Insuffecient Balance! ";
				cout << "\nAmmount to withdraw is: " << Ammount << endl;
				cout << "Your Balance is: " << Client1.AccountBalance;
				

			}
			else {
				cout << "\nAmmount Withdraw Successfully";
				cout << "\nNew Balance is: " << Client1.AccountBalance;
			}
			
		}
		else {
			cout << "\nOperation was cancelled.\n";
		}
		
		
	

		
		
		

	}

};

