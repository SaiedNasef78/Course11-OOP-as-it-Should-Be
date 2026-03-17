#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;
class clsUpdateClientScreen:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter First Name? \n";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name? \n";
		Client.LastName= clsInputValidate::ReadString();
		cout << "\nEnter Email? \n";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone ?\n";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance ?\n";
		Client.AccountBalance = clsInputValidate::ReadDoubleNumber();
		cout << "\nEnter Pin Code? \n";
		Client.PinCode = clsInputValidate::ReadString();





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
public :
	static void _ShowUpdateClientInfo() {
		if (!CheckAccessRight(clsUsers::pUpdateClient)) {
			return;
		}
		string AccountNumber = "";
		clsScreen::_DrawScreenHeader("Update Client Screen");

		cout << "\nPlease Enter Account Number? \n";
		AccountNumber=clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe Account Number Is Not Found, Enter again? ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		cout << "\nAre You Sure want to Update Client Info\n";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			cout << "\nUpdate Client Info\n";
			cout << "\n____________________________\n";
			_ReadClientInfo(Client);
		
			clsBankClient::enSaveResult svResult= Client.Save();
			switch (svResult) {
			case clsBankClient::enSuccessSave:
				cout << "\nAccount Updated Successfully \n";
				_PrintClient(Client);
				break;
			case clsBankClient::enFaildSave:
				cout << "\nError Account was not saved because it's Empty";
				break;

			}

		}

	}

};

