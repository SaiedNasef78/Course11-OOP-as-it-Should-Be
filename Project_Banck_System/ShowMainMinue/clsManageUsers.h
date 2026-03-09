#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUserListScreen.h"
#include "clsInputValidate.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUsers:protected clsScreen
{
private:
	/*static void _ShowManageUsers();*/
	enum enManageUsers {
		eShowlistusers=1,
		eAddNewusers=2,
		eDeleteUsers=3,
		eUpdate=4,

		eFindUsers=5,
		eMainMenue=6

	};
	
	static void _GoBackToManageUsers(  ) {
		
		cout << "\nPress Any One Key to go back to mange users......";
		system("pause>0");
		system("cls");
		ShowManageUsers();

	}
	
	
	static void _ShowManageUsers() {
		system("cls");
		/*cout << "\nManage Users Will Be here....";*/
		/*_GoBackToMainMenue(_ShowManageUsers);*/
		clsUserListScreen::ShowListUserScreen();

	}
	static void _ShowAddNewUsers() {
		/*cout << "\nAdd New Users Will Be Here....";*/
		clsAddNewUserScreen::ShowAddNewUserScreen();
		
	}
	static void _ShowDeleteUsers() {

		/*cout << "\nDelete Users Will Be Here....";*/
		clsDeleteUserScreen::ShowDeleteUsersScreen();

	}
	static void _ShowUpdateUsers() {

	//	cout << "\nUpdate Users Will Be Here....";
		clsUpdateUserScreen::ShowUpdateUserList();

	}
	static void _ShowFindUsers() {

		/*cout << "\nFind Users Will Be Here....";*/
		clsFindUserScreen::ShowFindUserScreen();
		

	}
	static void _PerformToManageUsers(enManageUsers Users) {
		system("cls");
		switch (Users)
		{
		case clsManageUsers::eShowlistusers:
		
			_ShowManageUsers();
			
			break;
		case clsManageUsers::eAddNewusers:
			
			_ShowAddNewUsers();
			
			break;
		case clsManageUsers::eDeleteUsers:
			
			_ShowDeleteUsers();
			
			break;
		case clsManageUsers::eUpdate:
		
			_ShowUpdateUsers();
			
			break;
		case clsManageUsers::eFindUsers:
		
			_ShowFindUsers();
			
			break;
		case clsManageUsers::eMainMenue:
			
			//clsSMainScreen::ShowMainMenue();
			break;
		default:
			break;
		}

		if (Users != enManageUsers::eMainMenue) {
			_GoBackToManageUsers();


		}





	}
	static int  _ReadUsersInfo() {
		
		cout << setw(37) << left << "" << "Choose What do you want to do [1 to 6]? ";
		return clsInputValidate::ReadIntNumberBetween(1, 6, "Please Enter Again? ");




	}

public :
	static void ShowManageUsers() {
		if (!CheckAccessRight(clsUsers::pManageUsers)) {
			return;
		}
		clsScreen::_DrawScreenHeader("Manage Users Screen");

		cout << "\n" <<setw(36) << left << "" << "==========================================\n";
	
			cout <<  setw(44) << left << "" << "Manage Users Menue\n";
		cout <<  setw(36) << left << "" << "==========================================\n";

		cout << setw(38) << left << "" << "[1] List Users. \n";
		cout << setw(38) << left << "" << "[2] Add New Users.\n";
		cout << setw(38) << left << "" << "[3] Delete Users .\n";
		cout << setw(38) << left << "" << "[4] Update Users. \n";
		cout << setw(38) << left << "" << "[5] Find Users .\n";
		cout << setw(38) << left << "" << "[6] Main Menue . \n";
		
		cout << setw(36) << left << "" << "==========================================\n";
		_PerformToManageUsers((enManageUsers)_ReadUsersInfo());

	}

};

