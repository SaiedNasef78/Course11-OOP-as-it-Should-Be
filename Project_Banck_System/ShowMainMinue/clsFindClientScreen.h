#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;
class clsFindClientScreen :protected clsScreen
{
private:
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

	static void _ShowFindClientInfo() {
		if (!CheckAccessRight(clsUsers::enPermissions::pShowClientList)) {
			return;
		}
		string AccountNumber = "";
		clsScreen::_DrawScreenHeader("Find Client Screen");
		cout << "\nPlease Enter Account Number? \n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Is Not Found ,Enter Another One? ";
			AccountNumber = clsInputValidate::ReadString();


		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		if (!Client1.IsEmpty()) {
			cout << "\nClient Found :-)\n";
		}
		else {
			cout << "\nClient was not Found :-(\n ";
		}
		_PrintClient(Client1);

	}


	
};