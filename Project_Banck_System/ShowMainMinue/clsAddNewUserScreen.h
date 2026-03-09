#pragma once
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidate.h"
class clsAddNewUserScreen:protected clsScreen
{

private:
	
	static  void _ReadUsersInfo(clsUsers &User)
	{
		
		
	
		cout << "\nEnter FirstName? ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name? ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email? ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone? ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password? ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permissions? ";
		User.Permition = _ReadPermissionsInfo();
	}
	static int _ReadPermissionsInfo() {
		int Permissions = 0;
		char Answer = 'n';
		cout << "\nDo You Want to give full access ?[y][n] \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			return -1;
		}
		cout << "\nDo You Want to give Access to : \n";
		cout << "\nShow Client List? \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUsers::pShowClientList;
		}

		cout << "\nAdd NewClient list? \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUsers::pAddNewClient;

		}

		cout << "\nDelete Client List? \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUsers::pDelelteClient;
		}

		cout << "\nUpdate Client List? \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUsers::pUpdateClient;

		}

		cout << "\nFind Client ? \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUsers::pFindClient;
		}

		cout << "\nTransActions Client? \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUsers::pTransActions;

		}

		cout << "\nManage Users? \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUsers::pManageUsers;

		}
		cout << "\nLogin Registor. \n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUsers::pLoginRegistor;
		}
		return Permissions;
	}
	/*static int ReadPermiision() {
		int per = 0;
		
		if (clsInputValidate::YesOrNo("\nDo you want to give access full ?[y][n] \n") == true) {
			return clsUsers::pAll;
		}
		string Arrper[] = { "ShowClient","AddNewClient","DeleteClient","UpdateClient","FindClient","TransActions","ManageUsers" };
		for (int i = 0; i < 7; i++) {
			if (clsInputValidate::YesOrNo("Do You Access " + Arrper[i] + "Permissions ? "))
				per += pow(2, i);

		}
		return per;
	}*/
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
	static void ShowAddNewUserScreen() {
		clsScreen::_DrawScreenHeader("AddNew User Screen");
		cout << "\nPlease Enter User name? ";
		string UserName = clsInputValidate::ReadString();
		while (clsUsers::IsUserExist(UserName)) {
			cout << "\n The UserName Is Alriedy Exist Enter Again? ";

			UserName = clsInputValidate::ReadString();


		}
		clsUsers User =clsUsers::GetAddNewUserObject(UserName);
	
		_ReadUsersInfo(User);
		cout << "\nAre You Sure to Add New User? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			clsUsers::enSaveResult sv= User.Save();
			switch (sv) {

			case clsUsers::eSuceessSave:

				cout << "\nUser Addeded Successfully :-) ";


				_PrintUser(User);
				break;
			case clsUsers::eFailSave:
				cout << "\nError User was not saved bacause it's simpl";
				break;


			case clsUsers::svFaildUserName:
				cout << "\nError User was not saved because UserName is used!\n";
				break;

			}
			
		}





	}

};

