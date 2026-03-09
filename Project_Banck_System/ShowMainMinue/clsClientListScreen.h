#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;
class clsClientListScreen:protected clsScreen
{
private:
	static void _PrintRecordLine(clsBankClient Client) {
		cout << " |" << left << setw(20) << Client.FullName();


		cout << "|" << left << setw(19) << Client.AccountNumber();
		cout << "|" << left << setw(20) << Client.AccountBalance;
		cout << "|" << left << setw(8) << Client.PinCode;
		cout << "|" << left << setw(25) << Client.Email;

	}
public:
	static void ShowClientList() {
		if (!CheckAccessRight(clsUsers::pShowClientList)) {
			return;
		}
		vector <clsBankClient> VClient = clsBankClient::GetClientList();
		string Title = "\tClient List Screen";
		string subTitle = "\t(" + to_string(VClient.size()) + ")Client(s)";
		clsScreen::_DrawScreenHeader(Title,subTitle);

		
		cout <<"\n\t_____________________________________________________________________________________________________\n";
		cout  << "\n\t|" << left << setw(19) << " ClientName";

		cout  << "|" << left << setw(20) << "Account Number";
		cout  << "|" << left << setw(20) << "Account Balance";
		cout  << "|" << left << setw(8) << "PinCode";
		cout <<  "|" << left << setw(25) << "Email" << "\n";
		cout  << "\n\t_____________________________________________________________________________________________________\n";
		if (VClient.size() == 0) {
			cout << "\t\t\t No Clients Avilable In The System!";


		}
		else {
			for (clsBankClient& Client : VClient) {

				cout << setw(7)<<left << "";
				_PrintRecordLine(Client);
				cout << "\n";

			}
		}
		cout << "\n\t___________________________________________________________________________________________\n";

	}
};

