#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "clsPerson.h"
#include "clsString.h"
#include "global.h"
using namespace std;
class clsBankClient:public clsPerson
{
public:	struct stLoginListScreen;
private:
	
	enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode=3 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;
	string DateAndTime;
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
		myFile.open("Clients.txt", ios::out);
		if (myFile.is_open()) {
			for (clsBankClient &c : vClinet) {
				if (c._MarkForDelete == false) {
					DateLine = _ConvertClientObjectToLine(c);
					myFile << DateLine << endl;
				}
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
	 void AddClientToFile(string Line) {

		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out | ios::app);
		 if (MyFile.is_open()) {

			 MyFile << "\n" << Line;
			 MyFile.close();
		 }

	 }
	 void _AddNewClient() {

		 AddClientToFile(_ConvertClientObjectToLine(*this));

	 }
	string  _PrepareTransferLogRecord(string UserName,double Ammount, clsBankClient DestinationClient,string Seperator="#//#") {
		 string TransferLog = "";
		 TransferLog += clsDate::_GetSystemDateTime() + Seperator;
		 TransferLog += AccountNumber() + Seperator;
		 TransferLog += DestinationClient.AccountNumber() + Seperator;
		 TransferLog += to_string(Ammount) + Seperator;
		 TransferLog += to_string(AccountBalance) + Seperator;
		 TransferLog += to_string(DestinationClient.AccountBalance) + Seperator;
		 TransferLog += UserName;

		 return TransferLog;

	 }
	void _RegistorTransferLog(string UserName,double Ammount, clsBankClient DestinationClient) {
		fstream MyFile;
		string stDataLine = _PrepareTransferLogRecord(UserName,Ammount, DestinationClient);
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << "\n" << stDataLine;
			MyFile.close();

		}



	}
	
	static stLoginListScreen _ConvertLoginScreenToLine(string Line,string Seprator="#//#") {
		vector <string> vLogScreen = clsString::Splite(Line, Seprator);
		stLoginListScreen sLogin;
		sLogin.DateAndTime = vLogScreen[0];
		sLogin.AccountNumFrom= vLogScreen[1];
		sLogin.AccountNumTo = vLogScreen[2];
		sLogin.Ammount = stod(vLogScreen[3]);
		sLogin.BalanceFrom = stod(vLogScreen[4]);
		sLogin.BalanceTo = stod(vLogScreen[5]);
		sLogin.UserName = vLogScreen[6];
		return sLogin;

	}
public:
	struct stLoginListScreen {

		string DateAndTime;
		string AccountNumFrom;
		string AccountNumTo;
		double Ammount;
		double BalanceFrom;
		double BalanceTo;
		string UserName;

	};
	clsBankClient() {

	};
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
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance() {
		return _AccountBalance;
}
	__declspec(property(get = GetAccountBalance, put = setAccountBalance)) double AccountBalance;
	void Print() {
		// No UI Related Code iside object.
		/*cout << "\nClient Card : ";
		cout << "\n__________________________";
		cout << "\nFirst Name     : " << FirstName;
		cout << "\nLast Name      : " << LastName;
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nAccNumber      : " << AccountNumber();
		cout << "\nAccount Balance: " << _AccountBalance;
		cout << "\nPassward       : " << PinCode;
		cout << "\n__________________________\n";*/

		

}
	static clsBankClient Find(string AccountNumber) {
	
		
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
	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());

	}
	static clsBankClient GetAddNewClient(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);


	}
	enum enSaveResult { enFaildSave = 0, enSuccessSave = 1,svFaildAccountNumber };
	void erase() {
		vector <clsBankClient> Vclient = LoadClientDataFromFile();
		for (vector<clsBankClient>::iterator it = Vclient.begin(); it != Vclient.end(); it++) {


			if ((*it).AccountNumber() == _AccountNumber) {
				Vclient.erase(it);
				break;
			}
		}
		*this = _GetEmptyClient();

	}
	bool Delete() {
		vector <clsBankClient> Vclient = LoadClientDataFromFile();
		for (clsBankClient& C : Vclient) {
			if (C._AccountNumber == _AccountNumber) {
				C._MarkForDelete = true;
				break;
			}



		}
		_SaveDataToFile(Vclient);
		*this = _GetEmptyClient();
		return true;

	}
	 void Deposit(double Ammount) {
		AccountBalance += Ammount;
		Save();

	}
bool  WithDraw(double Ammount) {
	if (Ammount > AccountBalance || Ammount < 0) {
		return false;

	}
	else {
		AccountBalance -= Ammount;
		Save();
		return true;
	}
	}

bool Transfer(double Ammount, clsBankClient& Destantions) {
	if (Ammount > AccountBalance || (AccountBalance==Destantions.AccountBalance))
		return false;

	WithDraw(Ammount);
	Destantions.Deposit(Ammount);
	_RegistorTransferLog(CurrentUser.UserName, Ammount, Destantions);
	return true;



}
	static vector<clsBankClient> GetClientList() {
		return LoadClientDataFromFile();
	}
	enSaveResult Save() {
		switch (_Mode) {

		case enMode::EmptyMode: {
			if (IsEmpty())

				return enFaildSave;

		}
		case enMode::UpdateMode: {
			_Update();
			return enSuccessSave;
		}
		case enMode::AddNewMode: {
			if (IsClientExist(_AccountNumber)) {

				return svFaildAccountNumber;

			}
			else
			{
				_AddNewClient();
				return enSuccessSave;
			}
		}

		default:
			return enFaildSave;

		}

	}
	
	 static double GetTotalBalances() {
		 vector <clsBankClient> vClient = GetClientList();
		double TotalBalances = 0;
		for (clsBankClient& C : vClient) {

			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;

	}
	static   vector<stLoginListScreen> GetTransferLoginListScreen() {

		  vector<stLoginListScreen> vTransferLogRecord;
		 fstream MyFile;
		 MyFile.open("TransferLog.txt", ios::in);
		 if (MyFile.is_open()) {
			 string Line;
			 stLoginListScreen TransferRecord;
			 while (getline(MyFile, Line)) {
				 TransferRecord = _ConvertLoginScreenToLine(Line);
				 vTransferLogRecord.push_back(TransferRecord);

			 }


			 MyFile.close();


		 }


		 return vTransferLogRecord;

	 }
};

