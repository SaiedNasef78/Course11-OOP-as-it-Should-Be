#pragma once
#include "clsScreen.h"
#include "clsUtility.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
private:
	static void _PrintRecordToClient(clsBankClient Client) {
		cout << "|" << setw(17) << left << Client.FullName();
		cout << "|" << setw(15) << left << Client.AccountNumber();
		cout << "|" << setw(17) << left << Client.AccountBalance;
		cout << "|" << setw(10) << left << Client.PinCode;
		cout << "|" << setw(20) << left << Client.Email ;



	}
	static void _ShowClientList(vector <clsBankClient> vClient) {

		
		
		cout << setw(20) << left << ""<< "_______________________________________________________________________________\n\n";
		cout << setw(20) << left << "" << "|" << setw(17) << left << "FullName";
		cout <<  "|" << setw(15) << left << "Account Number";
		cout <<  "|" << setw(17) << left << "Account Balance ";
		cout <<  "|" << setw(10) << left << "Pin Code";
		cout <<  "|" << setw(20) << left << "Email\n\n";
		cout << setw(8) << left << "" << "_______________________________________________________________________________\n";

		double TotalBalances = clsBankClient::GetTotalBalances();
		if (vClient.size() == 0) {
			cout << "\t\t\t\tNo Clients Available In the System! ";
		}
		else {
			for (clsBankClient& C : vClient) {
				TotalBalances += C.AccountBalance;
				cout << setw(20) << left << "";
				_PrintRecordToClient(C);
				cout << "\n";
			}

			cout << setw(20) << left << "" << "_______________________________________________________________________________\n";


			string Title = "Total Balances: " + to_string(TotalBalances);
			string subtitle = "( " + clsUtility::NumberToText((int)TotalBalances) + " )";
			clsScreen::_DrawScreenHeader(Title, subtitle);
		}
	}
	

public:
	void static ShowTotalBalances() {
		vector <clsBankClient> vClient = clsBankClient::GetClientList();
		string Title = "size(" + to_string(vClient.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader(Title);
		_ShowClientList(vClient);

		
		
	}



};

