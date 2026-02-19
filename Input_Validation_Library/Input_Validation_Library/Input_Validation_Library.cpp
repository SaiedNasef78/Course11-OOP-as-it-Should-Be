// Input_Validation_Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsDate.h"
#include "clsInputValidate.h"
#include "clsString.h"


using namespace std;
int main()
{
   
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(16, 2, 2026), clsDate(20, 2, 2026)) << endl;
	cout << clsInputValidate::IsDateBetween( clsDate(), clsDate(20, 2, 2026),clsDate(16, 2, 2026)) << endl;

	cout << "Please Enter a Number ?\n";
	int X= clsInputValidate::ReadIntNumber("Invalid Number ,Enter again: ");
	cout << "X= " << X;

	cout << "\nPlease Enter a Number Between 1 And 5: \n";
	int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number Is not within range");
	cout <<"Y= " << y;

	cout << "\nPlease Enter a Number ?\n";
	double x = clsInputValidate::ReadDoubleNumber("Invalid Number, Enter again ");
	cout << "x = " << x;

	cout << "\nPlease Enter a  Number Between 1 And 5: \n";
	double a = clsInputValidate::ReadDoubleNumberBetween(1, 5, "Invalid Number, Enter again ");
	cout << "A: " << a;
	cout << "\n";
	clsInputValidate::IsValidDate(clsDate(35, 2, 2026));


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
