#pragma once
#include <iostream>
#include <cstdlib>
#include "clsDate.h"
#include <ctime>
using namespace std;
class clsUtility
{
public:


	static int RandomNumber(int From, int To) {
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum;
}
	static void FillArrayWithRandomNumber(int Arr[], int Arrlength) {
		for (int i = 0; i < Arrlength; i++) {

			Arr[i] = RandomNumber(20, 40);
			cout << Arr[i] << endl;
		}


	}
	
	enum enCharacter{SmallLatter=1,CpaitalLatter,SpechialCharacter,Digit,MixChars};

	static char GetRandomCharacter(enCharacter Ch) {
		switch (Ch) {

		case enCharacter::SmallLatter:
			return char(RandomNumber(97, 122));

		case enCharacter::CpaitalLatter:
			return char(RandomNumber(65, 90));

		case enCharacter::SpechialCharacter:
			return char(RandomNumber(33, 47));

		case enCharacter::Digit:
			return char(RandomNumber(48, 57));
		case enCharacter::MixChars:
			return char(RandomNumber(33, 122));









}


	}

	static string GenerateWord(enCharacter ch,short NumberOfKeys) {
		string word="";
		for (int i = 0; i < NumberOfKeys; i++) {
			word += GetRandomCharacter(ch);

		}

		return word;

	}
	static void FillArrayWithRandomWords(string Arr[], int Arrlength,enCharacter Ch,int length) {
		for (int i = 0; i < Arrlength; i++) {

			
			for (int g = 1; g < length; g++) {
				Arr[i] += GetRandomCharacter(Ch);

			}
		}


	}
	static string GenerateKey(enCharacter ch)
	{
		string Key = "";
		Key = GenerateWord(ch, 4) + "-";
		Key = Key + GenerateWord(ch, 4) + "-";
		Key = Key + GenerateWord(ch, 4) + "-";
		Key = Key + GenerateWord(ch, 4);
		return Key;
	}
	static void GenerateKeys(short NumberOfKeys,enCharacter ch)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Kay [" << i << "] : " << GenerateKey(ch) << endl;
		}
	}
static	void FillArrayWithRandomKeys(string Arr[], int Arrlength, enCharacter ch) {
		for (int i = 0; i < Arrlength; i++) {

			Arr[i] += GenerateKey(ch);
			
		}


	}
	static void swaap(int &arr1, int &arr2) {
		int temp;

		temp = arr1;
		arr1 = arr2;
		arr2 = temp;

	}
	static void swaap(double& arr1,double& arr2) {
		double temp;

		temp = arr1;
		arr1 = arr2;
		arr2 = temp;

	}
	static void swaap(clsDate &d1, clsDate &d2) {
	
		d1.SwaapDate(d2);

	}
	static void ShufllArray(int Arr[100], int Arrlength) {

		for (int i = 1; i < Arrlength; i++) {
			swaap(Arr[RandomNumber(1, Arrlength) - 1], Arr[RandomNumber(1, Arrlength) - 1]);
		}


	}
	static void swaap(string& arr1, string& arr2) {
		string temp;

		temp = arr1;
		arr1 = arr2;
		arr2 = temp;

	}
	static void ShufllArray(string Arr[100], int Arrlength) {

		for (int i = 1; i < Arrlength; i++) {
			swaap(Arr[RandomNumber(1, Arrlength) - 1], Arr[RandomNumber(1, Arrlength) - 1]);
		}


	}
	static void FillArrayWithRandomNumbers(int Arr[100], short Arrlength, int From, int To) {
		for (int i = 0; i < Arrlength; i++) {

			Arr[i] = RandomNumber(From, To);

		}

	}
	static string Tabs(short T) {
		string TB = "";
		for (int i = 1; i <= T; i++) {
			TB += "\t";
			cout << TB;
		}
		return TB;
	}
	static string EncryptText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i < Text.length(); i++) {

			Text[i] = char((short)Text[i] + EncryptionKey);


		}
		return Text;

		//// Text = Saeed
		//// EncryptionKey = 2
		//for (int i = 0; i <= Text.length(); i++)
		//{ // Text.length() ( ????? ???? ??? ??? : ???? ????? ) ??????
		//	Text[i] = char((int)Text[i] + EncryptionKey);
		//	// Text[i] == (int) Text[S] == Text[83] + 2 == (char) Text[85] << U[0]; .....
		//}
		//return Text; // Ucggf
	}

	static string DecryptionText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
			// Text[i] == (int) Text[U] == Text[85] - 2 == (char) Text[83] << S[0]; .....
		}
		return Text; // Saeed
	}


	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

};
			
