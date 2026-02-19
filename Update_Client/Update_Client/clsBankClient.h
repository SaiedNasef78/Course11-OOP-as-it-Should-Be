#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsBankClient.h"
#include "clsPerson.h"
#include "clsString.h"
using namespace std;
class clsBankClient:public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	static clsBankClient _ConvertLinetoClientObjct(string Line,string Seperator= "#//#") {

		vector <string> Client = clsString::Splite(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, Client[0], Client[1], Client[2], Client[3], Client[4], Client[5], stod(Client[6]));
	}
	static clsBankClient _GetEmptyClient() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "",0);

	}
static	string _ConvertClientObjectToLine(clsBankClient Clinet,string seperator="#//#") {

		string Line;
		Line = Clinet.FirstName + seperator;
		Line += Clinet.LastName+ seperator;
		Line += Clinet.Email + seperator;
		Line += Clinet.Phone + seperator;
		Line += Clinet._AccountNumber + seperator;
		Line += Clinet.PinCode + seperator;
		Line += to_string(Clinet.AccountBalance);
		return Line;
	}
	static void _SaveDataToFile(vector<clsBankClient> vClinet) {
		fstream myFile;
		string DateLine;
		myFile.open("Clients.txt", ios::out| ios::app);
		if (myFile.is_open()) {
			for (clsBankClient c : vClinet) {
				DateLine = _ConvertClientObjectToLine(c);
				myFile<< DateLine << endl;
			}
			myFile.close();
		}


	}
	static vector <clsBankClient> LoadClientDataFromFile() {
		vector <clsBankClient> vClinet;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsBankClient Clinet = _ConvertLinetoClientObjct(line);
				vClinet.push_back(Clinet);




			}


			MyFile.close();

		}

		return vClinet;
	}
	 void _Update() {
		vector <clsBankClient> vClient;
		vClient = LoadClientDataFromFile();
		for (clsBankClient& C : vClient) {
			if (C.AccountNumber() == AccountNumber()) {
				C = *this;
				break;
			}

		}
		_SaveDataToFile(vClient);
	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance)
		:clsPerson( FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;


	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber() {
		return _AccountNumber;
	}
	void setPinCode(string PinCode) {
		
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(double AccountBalance) {
		AccountBalance = AccountBalance;
	}
	double GetAccountBalance() {
		return _AccountBalance;
}
	__declspec(property(get = GetAccountBalance, put = setAccountBalance)) double AccountBalance;
	void Print() {
		cout << "\nClient Card : ";
		cout << "\n__________________________";
		cout << "\nFirst Name     : " << FirstName;
		cout << "\nLast Name      : " << LastName;
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nAccNumber      : " << AccountNumber();
		cout << "\nAccount Balance: " << AccountBalance;
		cout << "\nPassward       : " << PinCode;
		cout << "\n__________________________\n";

		

}
	static clsBankClient Find(string AccountNumber) {
		vector <clsBankClient> vClient;
		
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile,Line)) {
				clsBankClient Client = _ConvertLinetoClientObjct(Line, "#//#");
				if (AccountNumber == Client._AccountNumber) {
					MyFile.close();
					return Client;


				}
				vClient.push_back(Client);
				


			}
			MyFile.close();


		}

		return _GetEmptyClient();





	}

	static clsBankClient Find(string AccountNumber, string PinCode) {
		vector <clsBankClient> vClient;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLinetoClientObjct(Line, "#//#");
				if ((AccountNumber == Client._AccountNumber)&& (PinCode==Client.PinCode)) {
					MyFile.close();
					return Client;


				}
				vClient.push_back(Client);



			}
			MyFile.close();


		}

		return _GetEmptyClient();





	}
	enum enSaveResult { enFaildSave = 0, enSuccessSave = 1 };
	enSaveResult Save() {
		switch (_Mode) {

		case enMode::EmptyMode:
			return enFaildSave;
			
		case enMode::UpdateMode:
			_Update();
			return enSuccessSave;



}



	}
	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());

}

};

