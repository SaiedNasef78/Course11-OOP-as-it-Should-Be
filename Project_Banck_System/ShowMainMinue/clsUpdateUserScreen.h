#pragma once
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidate.h"
#include "clsAddNewUserScreen.h"
class clsUpdateUserScreen:protected clsScreen
{
private:
	static void _ReadUserInfo(clsUsers& User) {
		cout << "\nEnter FirstName? ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName? ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email? ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone? ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password? ";
		User.Password= clsInputValidate::ReadString();

		cout << "\nEnter Permissions? ";
		User.Permition = _ReadPermissions();
		



	}
	static int _ReadPermissions() {
		int Per = 0;
		char A = 'n';
		cout << "\nDo you want to give full access [y][n]? ";
			cin >> A;
			if (A == 'y' || A == 'Y') {
				return clsUsers::enPermissions::pAll; //return  -1

			}
			cout << "\nDo You want to give access to: \n";
			cout << "\nShow Client List: ";
			cin >> A;
			if (A == 'y' || A == 'Y') {
				Per += clsUsers::pShowClientList;

			}
			cout << "\nAdd New Client: ";
			cin >> A;
			if (A == 'y' || A == 'Y') {
				Per += clsUsers::pAddNewClient;

			}

			cout << "\nFind Client List: ";
			cin >> A;
			if (A == 'y' || A == 'Y') {
				Per += clsUsers::pFindClient;
			}

			cout << "\nUpdate ClientList: ";
			cin >> A;
			if (A == 'y' || A == 'Y') {
				Per += clsUsers::pUpdateClient;
			}

			cout << "\nDelete Client List: ";
			cin >> A;
			if (A == 'y' || A == 'Y') {
				Per += clsUsers::pDelelteClient;
			}

			cout << "\nManage Users: ";
			cin >> A;
			if (A == 'y' || A == 'Y') {
				Per += clsUsers::pManageUsers;

			}
			cout << "\nTransactions : ";
			cin >> A;
			if (A == 'y' || A == 'Y') {
				Per += clsUsers::pTransActions;
			}
			cout << "\nShow Login Registor? \n";
			if (A == 'y' || A == 'Y') {
				Per += clsUsers::pLoginRegistor;
			}
			cout << "\nCurrency Exhange Screen.\n";
			cin >> A;
			if (A == 'Y' || A == 'y') {
				Per += clsUsers::pCurrencyExhange;
			}


			return Per;
	}
	static void _PrintUser(clsUsers User) {
		cout << "\n__________________________________________\n";
		cout << "User Card \n";
		cout << "__________________________________________\n";
		cout << "First Name: " << User.FirstName << endl;
		cout << "Last Name : " << User.LastName << endl;
		cout << "Email     : " << User.Email << endl;
		cout << "Phone     : " << User.Phone << endl;
		cout << "User Name : " << User.UserName << endl;
		cout << "Password  : " << User.Password << endl;
		cout << "Permissions: " << User.Permition << endl;




	}

public: 
	static void ShowUpdateUserList() {
		clsScreen::_DrawScreenHeader("Update User Screen");
		string UserName = "";
		cout << "\nPlease Enter User Name? ";
		UserName = clsInputValidate::ReadString();
		while (!clsUsers::IsUserExist(UserName)) {

			cout << "\nUser Name Is Not found, Choose anther one: ";
			UserName = clsInputValidate::ReadString();

		}
		clsUsers User = clsUsers::Find(UserName);
	
		_PrintUser(User);
		cout << "\nAre you sure you want to update users[y][n]? ";
		char Answer = 'n';
		cin >> Answer;

		
		if (Answer == 'y' || Answer == 'Y') {
			cout << "\n\nUpdate User Info:";
			cout << "\n_______________________________\n";
			_ReadUserInfo(User);
			clsUsers::enSaveResult sv = User.Save();
			switch (sv) {
			case clsUsers::eSuceessSave:
				
				cout << "\nUpdated Successfully:-) \n";
					_PrintUser(User);
					break;
			case clsUsers::svFaildUserName:
				cout << "\nError ,user name is not found ";
				break;

			case clsUsers::eFailSave:
				cout << "\nError,because User list is empty ";
				break;
				}

		}
		



	}








};

