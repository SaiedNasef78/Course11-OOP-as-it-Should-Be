#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsString.h"
class clsCurrencyCalculatorScreen:protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency,string Convert) {
		cout << Convert;
		cout << "\n_________________________________________________\n\n";
		cout << "\nCountry Name   :" << Currency.Country();
		cout << "\nCurrency Code  :" << Currency.CurrencyCode();
		cout << "\nCurrency Name  :" << Currency.CurrencyName();
		cout << "\nRate/(1$) =    :" << Currency.Rate();
		cout << "\n_________________________________________________\n\n";



	}
	static clsCurrency _GetCurrencies(string Message) {

		cout << Message;
		string CurrencyCode=
		clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency Is not found, choose onther one: ";
			CurrencyCode =clsInputValidate::ReadString();


		}

		return clsCurrency::FindByCode(CurrencyCode);

	}


	

	static float _ReadAmmount() {
		float A = 0;
		cout << "\nEnter Ammount to Exchange: ";
		A = clsInputValidate::ReadfloatNumber("Invalid enter again  ");
		return A;

	}
	static void _PrintCalculationCurrency(float Ammount, clsCurrency Currency1, clsCurrency Currency2) {

		if (Currency1.CurrencyCode() == Currency2.CurrencyCode()) {
			cout << "\nCurrency1 and Currency2 are the same. ";
			return;
		}
	
		if (Currency1.CurrencyCode() != "USD") {
			_PrintCurrency(Currency1, "\nCurrency From\n");

			float AmmountInUSD = Currency1.ConvertToUSD(Ammount);
			cout << Ammount << " " << Currency1.CurrencyCode() << " = " << AmmountInUSD << " USD";
		}
 		if (Currency2.CurrencyCode() == "USD") {
			return;
		}
		cout << "\n\nConverting from USD To: \n";
		_PrintCurrency(Currency2, "\nTo: \n");
		float AmmountInCurrency2 = Currency1.ConvertToOnther(Ammount, Currency2);

			cout << Ammount << " " << Currency1.CurrencyCode() << " = " << AmmountInCurrency2<< " " << Currency2.CurrencyCode();

	}
public :
	static void ShowCurrencyCalculatorScreen() {

		char A = 'n';
		do {
			system("cls");
		clsScreen::_DrawScreenHeader("Update Currency Screen");

		
		clsCurrency CurrencyFrom = _GetCurrencies("Please Enter Currency1 Code: \n");
		clsCurrency CurrencyTo =_GetCurrencies("Please Enter Currency2 Code: \n");
		float Ammount = _ReadAmmount();

		_PrintCalculationCurrency(Ammount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation y/n? ";
			cin >> A;
		} while (A == 'y' || A=='Y');

	}

};

