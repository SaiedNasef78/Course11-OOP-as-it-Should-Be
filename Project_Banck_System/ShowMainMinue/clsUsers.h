#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "clsDate.h"
#include "clsUtility.h"
class clsUsers:public clsPerson
{
public:struct  stLoginRegistor;
private:
	enum enMode {
		eEmptyMode = 1,
		eUpdateMode = 2,
		eAddNewMode=3
		
	};
	enMode _Mode=eEmptyMode;
	string _Password;
	string _UserName;
	int _Permissions=0;
	bool _MarkForDelete = false;
	static  clsUsers _ConvertLineToUserObject(string Line,string Seperator="#//#") {
		vector <string> vUser = clsString::Splite(Line, Seperator);
		return clsUsers(enMode::eUpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsUtility::DecryptionText(vUser[5]), stoi(vUser[6]));

	}
	static clsUsers _GetEmptyUsers() {
		return clsUsers(eEmptyMode, "", "", "", "", "", "",0);
	}
	static string _ConvertUserObjectToLine(clsUsers User,string Seperator = "#//#") {
		string Sword = "";
		Sword += User.FirstName + Seperator;
		Sword += User.LastName + Seperator;
		Sword += User.Email + Seperator;
		Sword += User.Phone+ Seperator;
		Sword += User.UserName + Seperator;
		Sword += clsUtility::EncryptText(User.Password)+ Seperator;
		Sword += to_string(User._Permissions);
		return Sword;
	} 
		static void _SaveDataToFile(vector<clsUsers> vUsers) {
			fstream MyFile;
			string Line;
			MyFile.open("Users.txt", ios::out);
			if (MyFile.is_open()) {
				
				
					for (clsUsers& c : vUsers) {
						if (c._MarkForDelete == false) {
							Line = _ConvertUserObjectToLine(c);
							MyFile << Line << endl;


						}


					}
					
			
				MyFile.close();
			}

	}
		
		static vector <clsUsers> _LoadDataUsersFromFile() {
			vector <clsUsers> vUsers;
			fstream MyFile;
			MyFile.open("Users.txt", ios::in);
			
			if (MyFile.is_open()) {
				string Line;
				while (getline(MyFile, Line)) {
					clsUsers Users = _ConvertLineToUserObject(Line);
					vUsers.push_back(Users);


				}

				MyFile.close();

			}

			return vUsers;
		}
		 void _Update() {
			vector <clsUsers> vUser = _LoadDataUsersFromFile();
			for (clsUsers& U : vUser) {

				if (U.UserName == UserName) {
					U = *this;
					break;
				}
			}
			_SaveDataToFile(vUser);
		}
		 void _AddUserToFile(string Line) {
			 fstream MyFile;
			 MyFile.open("Users.txt", ios::out | ios::app);
			 if (MyFile.is_open()) {

				 MyFile << "\n" << Line;
				 MyFile.close();

			 }

		 }
		 void _AddNewUsers() {

			 _AddUserToFile(_ConvertUserObjectToLine(*this));

		 }

	 string _PreparLoginInRecord(string delim="#//#") {

			 return (clsDate::_GetSystemDateTime() + delim + UserName + delim + clsUtility::EncryptText(Password)
				 + delim + to_string(Permition));
			
		}
	

	 static  stLoginRegistor _ConvertLoginRegistorLineToRecord(string Line, string Seperator = "#//#") {

		 vector <string> vLogin = clsString::Splite(Line, Seperator);
		 stLoginRegistor sLogin;
		 sLogin.DateAndTime = vLogin[0];
		 sLogin.UserName = vLogin[1];
		 sLogin.Password = vLogin[2];
		 sLogin.Permissions = stoi(vLogin[3]);

		 return sLogin;

	 }
public :
	clsUsers() {

	}
	enum enPermissions {
		pAll = -1,
		pShowClientList = 1,
		pAddNewClient = 2,
		pDelelteClient = 4,
		pUpdateClient = 8,
		pFindClient = 16,
		pTransActions = 32,
		pManageUsers = 64,
		pLoginRegistor=128,
		pCurrencyExhange=256
	};
	


	clsUsers(enMode Mode,string FirstName, string LastName, string Email, string Phone,string UserName,string Password,int Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_Password = Password;
		_Permissions = Permissions;
		_UserName = UserName;


}
	 void setPermissions(int Permissions) {
		_Permissions = Permissions;

	}
	 int GetPermissions() {
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = setPermissions)) int Permition;
	enMode Mode() {
		return _Mode;
	}
	void setUserName(string UserName) {
		_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = setUserName)) string UserName;

	void setPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = setPassword)) string Password;

	static clsUsers Find(string UserName) {
		fstream MyFile;
		
		
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUsers User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName) {
					MyFile.close();
					return User;
				
				}



			}
			MyFile.close();
		}
		return _GetEmptyUsers();
	}
	static clsUsers Find(string UserName, string Password) {
		fstream MyFile;
		
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUsers User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password) {
					MyFile.close();
					return User;

				}

}

			MyFile.close();

		}
		return _GetEmptyUsers();

	}
	bool IsEmpty() {
		return (enMode::eEmptyMode == _Mode);
	}
	static  bool IsUserExist(string UserName) {
		clsUsers User = Find(UserName);
			
		return !(User.IsEmpty());


	}
	static bool IsUserExist(string UserName, string Password) {
		clsUsers User = Find(UserName,Password);
		return !(User.IsEmpty());
	}
	static clsUsers GetAddNewUserObject(string UserName) {
		return clsUsers(eAddNewMode, "", "", "", "", UserName,"", 0);
	}
	enum enSaveResult {
		eFailSave = 1,
		eSuceessSave=2,
		svFaildUserName=3

	};
	enSaveResult Save() {
		switch (_Mode) {
		case enMode::eAddNewMode:
			if (IsUserExist(_UserName)) {
				return svFaildUserName;

			}
			else {
				_AddNewUsers();
				return eSuceessSave;
			}
			

		case enMode::eEmptyMode:
			
			return eFailSave;

		case enMode::eUpdateMode:
			_Update();
			return eSuceessSave;

		default:
			return eFailSave;






		}

	}
	bool Delete() {
		vector<clsUsers> vUser = _LoadDataUsersFromFile();
		for (clsUsers &u : vUser) {
			if (u.UserName == UserName) {
				u._MarkForDelete = true;
				break;
			}

		}
		*this = _GetEmptyUsers();
		_SaveDataToFile(vUser);
		return true;
	}
	static vector<clsUsers> GetUserList() {
		return _LoadDataUsersFromFile();
	}
	
	bool CheeckAccessPermissions(enPermissions Permissions) {
		if (Permissions == enPermissions::pAll)
			return true;
		else
			return  ((Permissions & this->Permition) == Permissions);
	}

	void LoginRegistor() {

		fstream MyFile;
		string Line = _PreparLoginInRecord();
		MyFile.open("LoginRegistor.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << Line << endl;
			MyFile.close();


		}
	}
	
	struct stLoginRegistor
	{
		string DateAndTime;
		string UserName;
		string Password;
		int Permissions;


	};


	static vector <stLoginRegistor> GetLoginRegistor() {
		fstream MyFile;
		vector <stLoginRegistor> vLogin;
		MyFile.open("LoginRegistor.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			stLoginRegistor sLogin;
			while (getline(MyFile, Line)) {
				sLogin = _ConvertLoginRegistorLineToRecord(Line);
				vLogin.push_back(sLogin);

			}


			MyFile.close();
		}


		return vLogin;
	}
};
