// TempletClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class T> 
class Calculator {
private:
    T Number1, Number2;

public:

    Calculator(T Num1, T Num2) {
        Number1 = Num1;
        Number2 = Num2;

    }
    T Add() {
        return Number1+Number2;
    }

    T Multiply() {
        return Number1 * Number2;
    }

    T Subtract() {
        return Number1 - Number2;
    }

    T Divide() {
        return Number1 / Number2;
    }
    void PrintCalculator() {
        cout << "\nNumber1:"<< Number1 << "  " << "Number2: " << Number2 << endl;
        cout << Number1 << " + " << Number2 << " = " << Add() << endl;
        cout << Number1 << " * " << Number2 << " = " << Multiply() << endl;
        cout << Number1 << " - " << Number2 << " = " << Subtract() << endl;
        cout << Number1 << " / " << Number2 << " = " << Divide() << endl;

    }

};


int main()
{
    Calculator <int> intCalculator(4, 5);
    Calculator <float> floatCalculator(4.6, 5.4);

    intCalculator.PrintCalculator();
    floatCalculator.PrintCalculator();
    
    system("pause>0");
    return 0;
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
