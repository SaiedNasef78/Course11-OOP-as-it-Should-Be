#pragma once
#include "clsString.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
class clsTransferLogScreen:protected clsScreen
{

private:
	static void _PrintLoginListFile(clsBankClient::stLoginListScreen &TransferLogRecord) {
		cout << endl<<setw(8) << left << "" << "| "<<setw(25) <<left<< TransferLogRecord.DateAndTime;
		cout << "| " << setw(12) << left << TransferLogRecord.AccountNumFrom;
		cout << "| " << setw(12) << left << TransferLogRecord.AccountNumTo;
		cout << "| " << setw(10) << left << TransferLogRecord.Ammount;
		cout << "| " << setw(12) << left << TransferLogRecord.BalanceFrom;
		cout << "| " << setw(12) << left << TransferLogRecord.BalanceTo;
		cout << "| " << setw(9) << left << TransferLogRecord.UserName;

	}

public:
	static void ShowLoginTransferScreen() {
		vector <clsBankClient::stLoginListScreen> vTransferLogRecord = clsBankClient::GetTransferLoginListScreen();
		string Title = " Transfer Login List Screen";

		string subtitle = "(" + to_string(vTransferLogRecord.size()) + ") Record(s)";
		clsScreen::_DrawScreenHeader(Title,subtitle);

		cout << "\n" << setw(8) << left << "" << "_________________________________________________________________________________"
			"____________________________\n\n";
		cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time";
		cout << "| " << setw(12) << left << "AccNum.From";
		cout << "| " << setw(12) << left << "AccNum.To";
		cout << "| " << setw(10) << left << "Ammount";
		cout << "| " << setw(12) << left << "BalanceFrom";
		cout << "| " << setw(12) << left << "BalanceTo";
		cout << "| " << setw(9) << left << "UserName";
		cout << "\n" << setw(8) << left << "" << "_________________________________________________________________________________"
			"____________________________\n";

		for (clsBankClient::stLoginListScreen& Log : vTransferLogRecord) {

			_PrintLoginListFile(Log);

		}
		cout << "\n" << setw(8) << left << "" << "_________________________________________________________________________________"
			"____________________________\n\n";
	}

};

