#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen:protected clsScreen
{
private:
	
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\nCurrency Card: ";
		cout << "\n_________________________________________________\n\n";
		cout << "\nCountry Name   :" << Currency.Country();
		cout << "\nCurrency Code  :" << Currency.CurrencyCode();
		cout << "\nCurrency Name  :" << Currency.CurrencyName();
		cout << "\nRate/(1$) =    :" << Currency.Rate();
		cout << "\n_________________________________________________\n\n";




	}
	static string _ReadCurrencyByCodeOrName(string Message) {
		
		cout << Message;
		
		return clsInputValidate::ReadString();
		

	}
	static short _ReadMenueOption() {
		
		cout << "Find By: [1] Code or [2] Country ? ";
		return (short)clsInputValidate::ReadIntNumberBetween(1,2,"Invalid Number,enter again ");


	}
	static void _ShowResult(clsCurrency C1) {

		if (!C1.IsEmptyMode()) {
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(C1);
			
		}
		else

		{

			cout << "\nCurrency Not Found :-(\n";
		}

		


	}
public :
	static void ShowFindCurrencyScreen() {

		clsScreen::_DrawScreenHeader("Find Currency Screen");
		short C=_ReadMenueOption();
		
		if (C == clsCurrency::enCurrency::eCode) {
			
			clsCurrency C1 = clsCurrency::FindByCode(_ReadCurrencyByCodeOrName("\nPlease Enter Code?  "));
			_ShowResult(C1);
		}
		else {
		
			
			clsCurrency C2 = clsCurrency::FindByCountry(_ReadCurrencyByCodeOrName("\nPlease Enter Country?  "));
			_ShowResult(C2);
			
		}
		

	}

};

