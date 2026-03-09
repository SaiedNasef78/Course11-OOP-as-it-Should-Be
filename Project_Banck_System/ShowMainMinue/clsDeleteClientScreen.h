#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsAddNewClients.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
class clsDeleteClientScreen:protected clsScreen
{

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
	static void _DeleteClientScreen() {
		if (!CheckAccessRight(clsUsers::pDelelteClient)) {
			return;
		}
		clsScreen::_DrawScreenHeader("Delete Client Screen");
		string AccountNumber;
		cout << "\nPlease Enter Account Number? \n";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nThe Account NUmber Is Not Found, enter again";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient client=clsBankClient::Find(AccountNumber);
		_PrintClient(client);
		cout << "\n Are You Sure Want To delete ";
		char Answer='n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (client.Delete())
			{
				cout << "\nClient Deleted Successfully\n";
				_PrintClient(client);
			}
			else
			{
				cout << "\n Error Client Was not Deleted\n";
			}

		}
		
		
		
		
	}
};

