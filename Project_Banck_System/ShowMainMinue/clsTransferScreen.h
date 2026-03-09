#pragma once

#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <fstream>
#include "clsDate.h"
#include "clsUsers.h"
class clsTransferScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {

		cout << "\n\nClient Card: ";
		cout << "\n\n______________________________________\n\n";
		cout << "Full Name : " << Client.FullName() << endl;
		cout << "Acc Number: " << Client.AccountNumber() << endl;
		cout << "Balance   : " << Client.AccountBalance;
		cout << "\n\n______________________________________\n\n";
	}

	static string _ReadAccountNumber(string Message) {
		
		string AccountNumber = "";
		cout << Message;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\n Account Number Is Not found, choose another one. ";
			AccountNumber = clsInputValidate::ReadString();


		}
		
		 return AccountNumber;

	}
static 	double ReadAmmount(clsBankClient TransferFrom) {
	double Ammount=0;
	
	cout << "\n Enter Transfer Ammount? ";
	Ammount = clsInputValidate::ReadDoubleNumber();

	while (TransferFrom.AccountBalance < Ammount) {

		cout << "\nAmmount Exceeds the avilable balance,Enter another ammount? ";
		Ammount = clsInputValidate::ReadDoubleNumber();

	}
	

		return Ammount;

	}





public :
	
static 	void ShowTransferScreen() {
		clsScreen::_DrawScreenHeader("Transfer Screen");

		clsBankClient TransferFrom = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Numebr to Transfer From: "));
		_PrintClient(TransferFrom);

		clsBankClient TransferTo = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Numebr to Transfer To: "));
		_PrintClient(TransferTo);

		
		double Ammount = ReadAmmount(TransferFrom);


		char A = 'n';
		cout << "\nAre you sure you want to perform this operation? [y][n]? ";
		cin >> A;
		if (A == 'y' || A == 'Y') {
			if (TransferFrom.Transfer(Ammount, TransferTo)) {
				cout << "\nTransfer Done Successfully ";

			}
			else {
				cout << "\nTransfer failed, because you wanted to depsit into the same account )-:";
				return;
			}
			
		}
		
		_PrintClient(TransferFrom);
		_PrintClient(TransferTo);

	}





};

