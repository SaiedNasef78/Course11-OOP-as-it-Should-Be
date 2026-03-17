#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
class clsCurrenciesListScreen:protected clsScreen
{
private:

	static void _PrintCurrenciesList(clsCurrency C1) {
		
		cout << setw(8) << left << "" << "| " << setw(25) << left << C1.Country();
		cout << "| " << setw(8) << left << C1.CurrencyCode();
		cout << "| " << setw(43) << left << C1.CurrencyName();
		cout << "| " << setw(15) << left << C1.Rate();


	}

public :

	static void ShowCurrenciesList() {
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "Currencies List Screen";
		string SubTitle = "(" + to_string(vCurrencies.size()) + ") Currency. ";
		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << endl << setw(8) << left << "" << "___________________________________________________________________________________"
			"______________________\n\n";
		cout << setw(8) << left << "" <<  "| " << setw(25) << left << "Country";
		cout << "| " << setw(8) << left << "Code";
		cout << "| " << setw(43) << left << "Name";
		cout << "| " << setw(15) << left << "Rate/(1$)\n";
		cout << endl << setw(8) << left << "" << "___________________________________________________________________________________"
			"______________________\n\n";
		if (vCurrencies.size() == 0) {
			cout << "\t\t\t\t\t\tNo Currencies Available In The System! ";

		}
		else {
			for (clsCurrency& C : vCurrencies) {

				_PrintCurrenciesList(C);
				cout << "\n";


			}

			cout << endl << setw(8) << left << "" << "___________________________________________________________________________________"
				"______________________\n\n";
		}
	}


};

