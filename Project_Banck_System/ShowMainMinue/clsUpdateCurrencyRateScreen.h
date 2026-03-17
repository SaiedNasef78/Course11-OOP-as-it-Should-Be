#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include <string>
#include "clsInputValidate.h"
class clsUpdateCurrencyRateScreen:protected clsScreen
{

private:
	static void  _PrintCurrency(clsCurrency Currency) {
		cout << "\nCurrency Card: ";
		cout << "\n_________________________________________________\n\n";
		cout << "\nCountry Name   :" << Currency.Country();
		cout << "\nCurrency Code  :" << Currency.CurrencyCode();
		cout << "\nCurrency Name  :" << Currency.CurrencyName();
		cout << "\nRate/(1$) =    :" << Currency.Rate();
		cout << "\n_________________________________________________\n\n";



	}
	static float _ReadNewRate() {

		cout << "Enter New Rate: ";
		//return  clsInputValidate::ReadfloatNumber("Invalid Number,enter again. ");
		float NewRate = 0;
		NewRate= clsInputValidate::ReadfloatNumber("Invalid Number,enter again. ");
		return NewRate;
	}
public :
	static void ShowUpdateCurrencyRateScreen() {


		clsScreen::_DrawScreenHeader("Update Currency Screen");

		string CurrencyCode = "";
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		while  (Currency.IsEmptyMode())
		{
			cout << "\nCurrency Is Not Found,choose another one. ";
			CurrencyCode = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCode(CurrencyCode);

		}
	
			_PrintCurrency(Currency);

			cout << "\nAre you sure you want to update of this currency [y]/[n]? ";
			char Answer = 'n';
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				cout << "\nUpdate Currency Rate:\n";
				cout << "\n____________________________________\n\n";
				
				Currency.UpdateRate(_ReadNewRate());

				cout << "\nCurrency Rate Updated Successfully :-) \n";
				_PrintCurrency(Currency);
			}
}

	
};

