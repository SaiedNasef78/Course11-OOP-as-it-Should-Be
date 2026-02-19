// Project1-Utility-Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <cmath>
#include "clsUtility.h"
#include "clsDate.h"
int main()
{
	srand((unsigned)time(NULL));
	cout << clsUtility::RandomNumber(5, 10) << endl;
	cout << clsUtility::GetRandomCharacter(clsUtility::MixChars) << endl;
	cout << clsUtility::GenerateWord(clsUtility::MixChars, 8) << endl;
	cout << clsUtility::GenerateKey(clsUtility::MixChars) << endl;
	clsUtility::GenerateKeys(10, clsUtility::MixChars);
	cout << "\n";
	//swaap int
	int x = 10;
	int y = 20;
	cout << "Befor Swaap: \n";
	cout << x << " " << y << endl;
	clsUtility::swaap(x, y);
	cout << "After Swaap: \n";
	cout << x << " " << y << endl;


	// swaap double
	double a = 10.5, b = 20.5;
	cout << "Befor Swaap: \n";
	cout << a << " " << b << endl;
	clsUtility::swaap(a, b);
	cout << "After Swaap: \n";
	cout << a << " " << b << endl;

	// swaap string
	string s1 = "Ali", s2 = "saied";
	cout << "Befor Swaap: \n";
	cout << s1 << " " << s2 << endl;
	clsUtility::swaap(s1, s2);
	cout << "After Swaap: \n";
	cout << s1 << " " << s2 << endl;

	// swaap Date
	clsDate Date1(19, 2, 2026), Date2(20, 2, 2022);

	clsUtility::swaap(Date1, Date2);
	cout << "After Swaap: \n";
	Date1.DateToString();
	cout << " ";
	Date2.DateToString();

	int arr[100];
	clsUtility::FillArrayWithRandomNumber(arr, 4);
	cout << endl;

	string Arr4[100];
	clsUtility::FillArrayWithRandomWords(Arr4, 5, clsUtility::MixChars, 8);
	cout << "\nAfter Fill Array With Random Words:\n";
	for (int i = 0; i < 5; i++) {
		cout << Arr4[i] << endl;

	}
	cout << "\nRandom Character: " << clsUtility::GetRandomCharacter(clsUtility::CpaitalLatter) << endl;
	string Arr3[100];
	cout << "\nAfter Fill Array With Random Keys:\n";
	clsUtility::FillArrayWithRandomKeys(Arr3, 5, clsUtility::MixChars);
	for (int i = 0; i < 5; i++) {
		cout << Arr3[i] << endl;

	}

	cout << "\n Array After Shuffle: \n";
	int arr6[5] = { 1,2,3,4,5 };
	clsUtility::ShufllArray(arr, 5);
	for (int i = 0; i < 5; i++) {


		cout << arr6[i] << endl;
	}
	//string 
	string Arr[5] = { "Saied","Nasef","Abdelguaad","gaballa","rheel" };
	clsUtility::ShufllArray(Arr, 5);
	for (int i = 0; i < 5; i++) {


		cout << Arr[i] << endl;
	}
	clsUtility::FillArrayWithRandomNumbers(arr, 5, 20, 50);
	cout << "\nArray After Fill: \n";
	for (int i = 0; i < 5; i++) {

		cout << arr[i] << endl;

	}
	cout << endl << "Text" << clsUtility::Tabs(5) << "Text2" << endl;
	cout << clsUtility::EncryptText("Saied Nasef Abdelguaad", 3) << endl;
	cout << clsUtility::DecryptionText("Saied Nasef Abdelguaad", 2) << endl;

		system("pause>0");
	return 0;

} 