// TempletFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<typename T> T MyMax(T Num1, T Num2) {
    return (Num1 > Num2) ? Num1 : Num2;


}
template<typename S> void swaap(S& a, S& b) {
    S temp = 0;

    temp = a;
    a = b;
    b = temp;

}
template <typename T> void PrintTwice(T g) {
    cout << g << " " << g;
}
template <typename j> bool IsEqual(j num1, j num2) {
    return (num1 == num2);
}
template <typename arr> arr LinearSerch(arr h[],arr n) {

    for (arr i = 0; i < 5;i++) {
        if (n == h[i]) {
            return i;
        }
    }
    return -1;
}
int main()
{
    cout << "int: " <<  MyMax<int> (3, 6)<< endl;
    cout << "float : " << MyMax<float>(4.5, 7.9) << endl;
    cout << "char : " << MyMax<char>('f', 'A');

    cout << "\nSwaap Two Number: \n";
    int m = 9;
    int h = 7;
  
    swaap(m, h);
    cout << m << " " << h << "\n\n";

    PrintTwice('f');

    cout << "\nIs Equal: \n";
   cout <<  IsEqual<int>(3, 3);

   cout << "\nLiener Serch: \n";
   int Arr[5] = {2,3,4,5,6};
   cout << LinearSerch <int>(Arr, 5);

    system("pause >0");
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
