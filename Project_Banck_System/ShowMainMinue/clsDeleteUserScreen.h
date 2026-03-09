#pragma once
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidate.h"
class clsDeleteUserScreen:protected clsScreen
{
private:
	
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
	static void ShowDeleteUsersScreen() {

		clsScreen::_DrawScreenHeader("Delete User Screen");
		

		cout << "\nPlease Enter UserName? \n";
		string UserName = clsInputValidate::ReadString();
		
		while (!clsUsers::IsUserExist(UserName)) {
			cout << "\nTUserName Is Not found , eChoose another one:  ";
			UserName = clsInputValidate::ReadString();

		}
		clsUsers deleteUser=clsUsers::Find(UserName);
		_PrintUser(deleteUser);
		cout << "\nAre you Sure you want to delete this user y/n ? ";
		char A = 'n';
		cin >> A;
		if (A == 'y' || A == 'Y') {
			if (deleteUser.Delete()) {
				cout << "\n User Deleted Successfully:-)\n";

				_PrintUser(deleteUser);

			}
			else {
				cout << "\nError deleted user name is not found? ";
			}



		}


	}

};

