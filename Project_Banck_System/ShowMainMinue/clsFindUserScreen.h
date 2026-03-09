#pragma once
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidate.h"
class clsFindUserScreen:protected clsScreen
{
private:
	static void _getPermisstions(int Per) {
		string ArrPer[] = { "ShowClientList","Add New Client","Delete Client","Update Client","Find Client","Transactions","ManageUser","LoginRegistor"};
		
		for (int i = 0; i < 8; i++) {
			if (Per == clsUsers::enPermissions::pAll) {
				cout << ArrPer[i] << endl;
			}
			else if (Per & (1 << i)) {
				cout << ArrPer[i] << endl;

			}


	}




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
		cout << "\n____________________________________________\n";
		_getPermisstions(User.Permition);




	}

public :
	static void ShowFindUserScreen() {
		
		clsScreen::_DrawScreenHeader("Find User Screen");

		cout << "\nPlease Enter User Name? ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUsers::IsUserExist(UserName)) {
			cout << "\nUser Name IsNot Found,Choose another one: ";
			UserName = clsInputValidate::ReadString();


		}
		clsUsers User = clsUsers::Find(UserName);
		
		if (!User.IsEmpty()) {

			cout << "\nUser is found :-)\n";
			_PrintUser(User);
		}
		else
		{
			cout << "\nUser is not found (-:\n";
		}


	}

};

