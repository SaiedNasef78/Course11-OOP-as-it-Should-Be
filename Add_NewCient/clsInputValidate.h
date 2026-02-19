#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"
using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(short Num, short From, short To) {

		return (Num >= From && Num <= To);

	}
	static bool IsNumberBetween(int Num, int From, int To) {

		return (Num >= From && Num <= To);

	}
	static bool IsNumberBetween(double Num, double From, double To) {

		return (Num >= From && Num <= To);

	}
	static bool IsNumberBetween(float Num, float From, float To) {
		return (Num >= From && Num <= To);

	}
	static bool IsDateBetween(clsDate D, clsDate From, clsDate To) {
		
		if ((clsDate::IsDate1EqualDate2(D, From) || D.IsDate1AfterDat2(From)) && (clsDate::IsDate1BeforeDate2(D, To) || clsDate::IsDate1EqualDate2(D, To))) {

			return true;
	}
		if  ((clsDate::IsDate1EqualDate2(D, To) || D.IsDate1AfterDat2(To)) && (clsDate::IsDate1BeforeDate2(D, From) || clsDate::IsDate1EqualDate2(D, From)));
		{
			return true;
		}
		return false;
	}
	static int ReadIntNumber(string ErrorMessage="Invalid Number,enter again? ") {
		int num;
		
		while (!(cin>>num)) {
			cin.clear();
			cin.ignore(numeric_limits < streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
			


		}
		return num;

	}
	static int ReadIntNumberBetween(int from, int to, string Meassage) {
		int num=ReadIntNumber();
		while (!IsNumberBetween(num, from, to)) {
			cout << Meassage << endl;
			
			num = ReadIntNumber();
		}
		return num;
	}
	static double  ReadDoubleNumber() {
		double num;
		
	
		while (!(cin>>num)) {
			cin.clear();
			cin.ignore(numeric_limits < streamsize>::max(), '\n');
			cout << "Error ,Enter Again ?" << endl;
			


		}
		
		return num;

	}
	static float ReadfloatNumber(string Message) {
		float num;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits < streamsize>::max(), '\n');

			cout << Message;
		}
		return num;

	}

	static double ReadDoubleNumberBetween(double From, double To, string Message) {
		double num = ReadIntNumber();
		while (!IsNumberBetween(num, From, To)) {
			cout << Message << endl;

			num = ReadIntNumber();
		}
		

		return num;

	}
	static string ReadString() {
		string s;
		getline(cin >> ws, s);
		return s;

	}
	static void IsValidDate(clsDate d) {
		if (d.IsValidateDate(d)) {
			cout << "\n\nYes, Is a validate Date";
		}
		else {

			cout << "\n\nNo, Is a Not validate Date";

		}
	}
	
};

