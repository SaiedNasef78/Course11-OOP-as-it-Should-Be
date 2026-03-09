#pragma once

#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iostream>
#include "clsScreen.h"
using namespace std;

class clsAddNewClients:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter FirstName? ";
		Client.FirstName = clsInputValidate::ReadString();
			cout << "\nEnter LastName? ";
			Client.LastName = clsInputValidate::ReadString();
			cout << "\nEnter Account Balance? ";
			Client.AccountBalance = clsInputValidate::ReadDoubleNumber();
			cout << "\nEnter Phone Number? ";
			Client.Phone = clsInputValidate::ReadString();
			cout << "\nEnter Pin Code? ";
			Client.PinCode = clsInputValidate::ReadString();
			cout << "\nEnter Your Email? ";
			Client.Email = clsInputValidate::ReadString();


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
	friend class clsDeleteClientScreen;

 
public :
	static void AddNewClient() {
		if (!CheckAccessRight(clsUsers::pAddNewClient)) {
			return;
		}
		string AccountNumber;
		clsScreen::_DrawScreenHeader("Add New Client Screen");
		cout << "Please Enter Account Number ?\n";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Is Already Used ,Choose another one?";
			AccountNumber = clsInputValidate::ReadString();
		}
	
		clsBankClient Client = clsBankClient::GetAddNewClient(AccountNumber);
		

		_ReadClientInfo(Client);
		clsBankClient::enSaveResult svResult = Client.Save();
	
		switch (svResult) {
		case clsBankClient::enSuccessSave:
			cout << "\nAccount Addeded Successfully";
			system("pause>0");
			system("cls");
			_PrintClient(Client);
			break;
		case clsBankClient::enFaildSave:
			cout << "\nError account was not saved because it's Empty ";
			break;
		case clsBankClient::svFaildAccountNumber:
			cout << "\n Error account was not saved because it's Empty";
			break;
		}
	}
};

