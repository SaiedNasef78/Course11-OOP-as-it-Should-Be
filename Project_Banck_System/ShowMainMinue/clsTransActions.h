#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsSMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsMoneyTransferScreen.h"
#include "clsTransferScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferLogScreen.h"
#include <iomanip>
#include <iostream>
using namespace std;
class clsTransActions:protected clsScreen
{
private:
	
	enum enTransActionMenue {
		eDeposit = 1,
		eWithdraw = 2,
		eMoneyTransfer=3,
		eTransferLoginSceen=4,
		eTotalBalance = 5,
		
		eMainMenue = 6

	};
	static void _PrintClientInfo(clsBankClient Client) {

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
	static void ShowDeposit() {
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Is Not Found,Choose anothe one ";
			AccountNumber = clsInputValidate::ReadString();



		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(Client1);
		cout << "\nPlease Enter a Deposit Account Balance ";
		double Balance = clsInputValidate::ReadDoubleNumber();
		char Answer = 'n';
		cout << "\nDo You Want Deposit Acount Balance [y][n]? ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Client1.AccountBalance += Balance;
			cout << "\nDone Successfully New Balance Is:" << Client1.AccountBalance << endl;
		}

		

	}
	static  void _GoToBackTransActionsScreen() {
		cout << "\nPress Any One Key to go back to TransActions......";
		
		system("pause>0");
		ShowTransActionsScreen();


	}
	static void _DepositScreen() {
		/*cout << "Deposit Will Be Here....\n";*/
		clsDepositScreen::ShowDepositScreen();
	}
	static void _WithDrawScreen() {
		/*cout << "WithDraw Will Be Here....\n";*/
		clsWithdrawScreen::ShowWithDrawScreen();
	}
	static void _MoneyTransfer() {
		/*cout << "Money Transfer  Will Be Here....\n";*/
		//clsMoneyTransferScreen::ShowTransferMoneySenderToReceiver();
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransferLoginScreen() {

		clsTransferLogScreen::ShowLoginTransferScreen();


	}
	static void _TotalBalance() {

		//cout << "Total Balance Will Be Here....\n";
		clsTotalBalancesScreen::ShowTotalBalances();

	}
	static int _ReadMenueOptions() {
		cout << setw(37) << left << "" << "Choose What do you want to do [1 to 6]? ";
		return clsInputValidate::ReadIntNumberBetween(1, 6, "Please Enter Again? ");

	}
		
	static void _PerformTransActionMenueOptions(enTransActionMenue MenueOptions) {

		switch (MenueOptions)
		{
		case enTransActionMenue::eDeposit:
			system("cls");
			_DepositScreen();
			_GoToBackTransActionsScreen();
			break;
		case enTransActionMenue::eWithdraw:
			system("cls");
			_WithDrawScreen();
			_GoToBackTransActionsScreen();
			break;

		case enTransActionMenue::eMoneyTransfer:
			system("cls");
			_MoneyTransfer();
			_GoToBackTransActionsScreen();
			break;
		case enTransActionMenue::eTransferLoginSceen:
			system("cls");
	
			_ShowTransferLoginScreen();
			_GoToBackTransActionsScreen();
			break;
		case enTransActionMenue::eTotalBalance:
			system("cls");
			_TotalBalance();
			_GoToBackTransActionsScreen();
			break;
		case enTransActionMenue::eMainMenue:


			// do nothing here the main screen will handle it :-)
			break;
		}




	}
public:
	static void ShowTransActionsScreen() {
		if (!CheckAccessRight(clsUsers::pTransActions)) {
			return;
		}
		system("cls");
		clsScreen::_DrawScreenHeader("TransActions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" <<"\t\tTransActions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
		cout << setw(37) << left << "" << "\t[3] MoneyTransfer Client To Client .\n";
		cout << setw(37) << left << "" << "\t[4] Transfer Login.\n";
		cout << setw(37) << left << "" << "\t[5] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[6] MainMenue.\n";
		cout << setw(37) << left << ""<<"===========================================\n";
		_PerformTransActionMenueOptions((enTransActionMenue)_ReadMenueOptions());
}

};

