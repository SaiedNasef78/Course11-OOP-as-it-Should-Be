#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsMoneyTransferScreen:protected clsScreen
{
private :
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
	static string _ReadAccountNumber() {
		cout << "\nPlease Enter Account Number? ";
		string AccNum = "";
		AccNum = clsInputValidate::ReadString();
		return AccNum;
	}
	static void _ReadAccountNumberInSenderAndReciever(clsBankClient& Sender, clsBankClient& Receiver) {

		string AccountNumber = "";
		AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccountNumber Is Not found enter again? ";
			AccountNumber = _ReadAccountNumber();;


		}
		Sender = clsBankClient::Find(AccountNumber);
		cout << "\n________________________\n";
		cout << "Client Sender \n";
		_PrintClient(Sender);

		AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccountNumber Is Not found enter again? ";
			AccountNumber = _ReadAccountNumber();;


		}
		Receiver = clsBankClient::Find(AccountNumber);;

		cout << "\n________________________\n";
		cout << "Client Receiver \n";
		_PrintClient(Receiver);





	}
	static void _TransferMoneySenderToReceiver(clsBankClient &Sender, clsBankClient &Receiver) {

		_ReadAccountNumberInSenderAndReciever(Sender, Receiver);
		
		cout << "\nPlease Enter Ammount ?";
		double Ammount = clsInputValidate::ReadDoubleNumber();
		
		
		cout << "\nAre You Sure you want to perform this transactions? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (Sender.WithDraw(Ammount)) {
				Receiver.Deposit(Ammount);
				cout << "\nAmmount Withdraw Successfully";
				cout << "\nNew Balance is Sender : " << Sender.AccountBalance << endl;
				cout << "\nNew Balance is Receiver : " << Receiver.AccountBalance << endl;
			}
			else {
				cout << "\nCannot withdraw, Insuffecient Balance! ";
				cout << "\nAmmount to withdraw is: " << Ammount << endl;
				cout << "Your Balance is: " << Sender.AccountBalance;

			}




		}
		else {
			cout << "\nOperation was cancelled.\n";
		}

	}


public:
	static void ShowTransferMoneySenderToReceiver() {
		clsScreen::_DrawScreenHeader("Transfer Money From Sender To Receiver");


		clsBankClient Sender,Receiver;
		_TransferMoneySenderToReceiver(Sender, Receiver);




	}

};

