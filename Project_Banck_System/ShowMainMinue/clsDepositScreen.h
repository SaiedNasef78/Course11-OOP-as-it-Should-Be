#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;
class clsDepositScreen:clsScreen
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
	static void _Deposit(string AccountNumber,double Amount) {
		vector <clsBankClient> vClient = clsBankClient::GetClientList();
		for (clsBankClient& C : vClient) {
			if (AccountNumber == C.AccountNumber()) {
				C.AccountBalance += Amount;
				
				break;
			}

			clsBankClient::enSaveResult svResult = C.Save();
		}
		

	}
	static string _ReadAccountNumber() {
		string AccountNumber = "";
		cout << "\nplease Enter Account Number? ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
public:
static  void ShowDepositScreen() {
		
		clsScreen::_DrawScreenHeader("Deposit Screen");
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nThe Account Number Is Not Found, enter again ";

			AccountNumber = clsInputValidate::ReadString();


		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		double Ammount;
		cout << "\nPlease Enter  Deposit Ammount ? ";
		Ammount = clsInputValidate::ReadDoubleNumber();
		cout << "\nAre You Sure to Deposit Ammount? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (Ammount < 0) {
				cout << "\nThe Ammount Is Negative!";
			}
			Client1.Deposit(Ammount);

			cout << "\nDeposit Successfully";
			cout << "\nNew Balance is: " << Client1.AccountBalance;

		}
		else {
			cout << "\nOperation was cancelled.\n";
		}



	}


};

