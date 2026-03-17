#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"
#include <string>
class clsCurrency
{
private:
	enum enMode {
		EmptyMode = 1,
		UpdateMode = 2,
	};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static clsCurrency _ConvertLineToCourrenceObject(string Line, string Seperator = "#//#") {
		vector <string> vCurrency = clsString::Splite(Line, Seperator);
		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));



	}
	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {

		string Sword = "";

		Sword += Currency._Country + Seperator;
		Sword += Currency._CurrencyCode + Seperator;
		Sword += Currency._CurrencyName + Seperator;
		Sword += to_string(Currency._Rate);
		return Sword;
	}
	static vector <clsCurrency> _LoadDataCurrencyFromFile() {
		fstream MyFile;
		vector <clsCurrency> vCurrency;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			
			while (getline(MyFile, Line)) {
				clsCurrency Courrecy = _ConvertLineToCourrenceObject(Line);
				vCurrency.push_back(Courrecy);
			}

			MyFile.close();
		}

		return vCurrency;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrency) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open()) {

			string Line;
			for (clsCurrency& C : vCurrency)
			{
				Line = _ConvertCurrencyObjectToLine(C);
				MyFile << Line <<endl;

			}
			MyFile.close();
		}


	}
	void _Update() {
		vector <clsCurrency> vCurrency = _LoadDataCurrencyFromFile();
		for (clsCurrency& C : vCurrency) {
			
			if (C._CurrencyCode == _CurrencyCode) {
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrency);
	}

	static clsCurrency _GetEmptyCurrencyObject() {

		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}
	clsCurrency(){

	}
	bool IsEmptyMode() {
		return _Mode == enMode::EmptyMode;
	}
	//Read only
	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;

	}
	string CurrencyName() {
		return _CurrencyName;

	}
	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();

	}
	float Rate() {
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode) {
		fstream MyFile;
		CurrencyCode = clsString::UpperCapitalLatter(CurrencyCode);
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while(getline(MyFile,Line)){

				clsCurrency C = _ConvertLineToCourrenceObject(Line);


				if (C.CurrencyCode() ==CurrencyCode) {

					MyFile.close();
					return C;
				}

			}

			MyFile.close();

		}
		return _GetEmptyCurrencyObject();

	}
	enum enCurrency {
		
		eCode = 1,
		eCountry = 2,

	};
	static clsCurrency Find(string serchkey, enCurrency Currence) {
		fstream MyFile;
		serchkey = clsString::UpperCapitalLatter(serchkey);
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {

				clsCurrency C = _ConvertLineToCourrenceObject(Line);

				switch (Currence) {
				case enCurrency::eCountry: {

					if (C.Country() == serchkey) {

						MyFile.close();
						return C;
					}
				}
				case enCurrency::eCode: {


					if (C.CurrencyCode() == serchkey) {

						MyFile.close();
						return C;
					}
				}

				}
			}
				MyFile.close();


			
		}
			return _GetEmptyCurrencyObject();
		

	}

	

	static clsCurrency FindByCountry(string Country) {
		fstream MyFile;
		Country = clsString::UpperCapitalLatter(Country);
		vector <clsCurrency> vCurrency = _LoadDataCurrencyFromFile();
		MyFile.open("Currencies.txt",ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency C = _ConvertLineToCourrenceObject(Line);

				if (clsString::UpperCapitalLatter(C.Country()) == Country) {
					MyFile.close();
					return C;
				}



			}
		
			MyFile.close();

		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return (!Currency.IsEmptyMode());

	}

	static vector<clsCurrency> GetCurrenciesList() {

		return _LoadDataCurrencyFromFile();
	}
	float ConvertToUSD(float Ammount) {

		return ((float)(Ammount /Rate() ));

	}
	float ConvertToOnther(float Ammount, clsCurrency Currency) {
		float AmmountToUSD = ConvertToUSD(Ammount);

		if (Currency.CurrencyCode() == "USD") {
			return AmmountToUSD;
		}
		return ((float)(Currency.Rate() * AmmountToUSD));


	}
};

