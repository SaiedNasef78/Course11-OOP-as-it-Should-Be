#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsers.h"
#include <iomanip>
#include <iostream>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyMainScreen:protected clsScreen
{
private:
	enum enCurrencyMainMenue {
		eListCurrencies = 1,
		eFindCurrency = 2,
		eUpdateRate = 3,
		eCurrancyCalculator = 4,
		eMainMenue = 5

	};
	/*void ShowCurrancyExhange();*/
 static int  _ReadCurrencyMainMenueOption() {
	cout <<"\n"<< setw(37) << left << "" << "Choose what do you want to do [1 to 5]? \n";
	cout << "\n" << setw(37) << left << "";
		return clsInputValidate::ReadIntNumberBetween(1, 5,"Invalid Number,Enter again");


	}
	static void _ShowListCurrencies() {

		//cout << "List Currencies List Screen Will Be here.\n";
		clsCurrenciesListScreen::ShowCurrenciesList();

	}
	static void _ShowFindCurrencies() {

		//cout << "List Find Currencies  Screen Will Be here.\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRate() {
		//cout << "List Update Currencies  Screen Will Be here.\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrenciesCalculator() {

		//cout << "List Calculator Currencies  Screen Will Be here.\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _GoToBackMainMeneu() {
		cout << "\nPress Any One Key to go back to main menue......";
		system("pause>0");
		ShowCurrancyExhange();

	}
	static void _PerformCurrencyMainMenueOption(enCurrencyMainMenue OptionMenue) {
		system("cls");
		switch (OptionMenue) {

		case enCurrencyMainMenue::eListCurrencies:

			_ShowListCurrencies();
			_GoToBackMainMeneu();
			break;

		case enCurrencyMainMenue::eFindCurrency:

			_ShowFindCurrencies();
			_GoToBackMainMeneu();
			break;

		case enCurrencyMainMenue::eUpdateRate:
			_ShowUpdateRate();
			_GoToBackMainMeneu();
			break;

		case enCurrencyMainMenue::eCurrancyCalculator:
			_ShowCurrenciesCalculator();
				_GoToBackMainMeneu();
			break;

		case enCurrencyMainMenue::eMainMenue:
			// do nothing here the main screen will handle it :-);
			break;


		}







	}

public:
	static  void ShowCurrancyExhange() {
		if (!clsScreen::CheckAccessRight(clsUsers::enPermissions::pCurrencyExhange)) {
			return;

		}
		system("cls");
		clsScreen::_DrawScreenHeader("Currency Exhange Main Screen");

		cout << setw(37) << left << "" << "====================================================\n";

		cout << setw(45) << left << "" << "Currency Exhange Menue\n";
			cout << setw(37) << left << "" << "====================================================\n";
			cout << setw(39) << left << "" << "[1] List Currencies.\n";
			cout << setw(39) << left << "" << "[2] Find Currency  .\n";
			cout << setw(39) << left << "" << "[3] Update Rate.\n";
			cout << setw(39) << left << "" << "[4] Currency Calculator.\n";
			cout << setw(39) << left << "" << "[5] Main Menue.\n";
			cout << setw(37) << left << "" << "====================================================\n";

			_PerformCurrencyMainMenueOption((enCurrencyMainMenue)_ReadCurrencyMainMenueOption());

	}



};

