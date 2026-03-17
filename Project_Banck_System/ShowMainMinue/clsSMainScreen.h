#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsClientListScreen.h"
#include "clsAddNewClients.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransActions.h"
#include "clsManageUsers.h"
#include "clsLoginRegistorScreen.h"
#include "clsUsers.h"
#include "clsCurrencyMainScreen.h"

#include "global.h"
using namespace std;


class clsSMainScreen :protected clsScreen {
private :

	static void _ShowClientList() {
		/*cout << "Client List Screen Will Be here.....\n";*/
		
			clsClientListScreen::ShowClientList();

		
		
}
	static void _AddNewClient() {
		/*cout << "Add New Client Will Be here.....\n";*/
		
			clsAddNewClients::AddNewClient();
		
		
	}
	static void _DeleteClient() {

		/*cout << "Delete Client Will Be here.....\n";*/
		
			clsDeleteClientScreen::_DeleteClientScreen();
		
		

	}
	static void _UpdateClient() {

		/*cout << "Update Client Info Will Be here.....\n";*/
		
			clsUpdateClientScreen::_ShowUpdateClientInfo();
		
		
	}
	static void _FindClient() {
		/*cout << "Find Client Will Be here.....\n";*/

		
			clsFindClientScreen::_ShowFindClientInfo();
	
		

	}
	static void _Transaction() {

		/*cout << "Transaction Will Be here.....\n";*/
		
			clsTransActions::ShowTransActionsScreen();
		

		
	}
	static void _ManageUsers() {
		//cout << "Manage Users Will Be here......\n";
		
			clsManageUsers::ShowManageUsers();
		
		

	}
	static void _ShowCurrencyExhangeScreen() {
		clsCurrencyMainScreen::ShowCurrancyExhange();


	}
	static void _ShowLoginScreen() {
		clsLoginRegistorScreen::ShowLoginScreen();
	}
	 static void _GoToBackMainMenue() {
		 
		cout << "\nPress Any One Key to go back to main menue......";
		system("pause>0");
		ShowMainMenue();


	}

	enum enMainMinue {
		ShowClient = 1, AddNewClient = 2, DelelteClient = 3
		, UpdateClient = 4, FindClient = 5, TransAction = 6,
		ManageUsers=7,LoginRegistr=8,CurrecyExhange=9,Exist=10
	};
	static void _PerformMainMenueOption(enMainMinue OperationMainMenue) {
		
		switch (OperationMainMenue) {
			
			
		case enMainMinue::ShowClient: {

			system("cls");
			
				_ShowClientList();
			_GoToBackMainMenue();
			break;
		}
		case enMainMinue::AddNewClient: {
			system("cls");
			
				_AddNewClient();
			_GoToBackMainMenue();
			break;
		}
		case enMainMinue::DelelteClient: {
			system("cls");
			
				_DeleteClient();
			_GoToBackMainMenue();
			break;
		}

		case enMainMinue::UpdateClient: {
			system("cls");
			
				_UpdateClient();
			_GoToBackMainMenue();
			break;
		}
		case enMainMinue::FindClient: {
			system("cls");
			
				_FindClient();
			_GoToBackMainMenue();
			break;
		}
		case enMainMinue::TransAction: {
			system("cls");
			
				_Transaction();
			_GoToBackMainMenue();
			break;
		}
		case enMainMinue::ManageUsers: {
			system("cls");
			
				_ManageUsers();
			
			_GoToBackMainMenue();
			break;
		}
		case enMainMinue::LoginRegistr:
		{
			system("cls");
			_ShowLoginScreen();
			_GoToBackMainMenue();
			break;

		}

		case enMainMinue::CurrecyExhange:
		{

			system("cls");
			_ShowCurrencyExhangeScreen();
			_GoToBackMainMenue();
			break;

		}

		case enMainMinue::Exist: {
			
			CurrentUser = clsUsers::Find("", "");
			 
			/*system("cls");*/
			break;
		}
		}


	}
	static short _ReadMainMenue() {
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 10] ?\n";
		cout << setw(37) << left << "";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "please enter number again? ");
		return Choice;

	}


public:

	static	void ShowMainMenue() {
		system("cls");
		_DrawScreenHeader("MainScreen");
		cout << left << setw(37) <<"" << "=========================================================\n";
		cout << left << setw(39) << "" << "[1] Show Client List.\n";
		cout << left << setw(39) << "" << "[2] Add New Client.\n";
		cout << left << setw(39) << "" << "[3] Delete Client.\n";
		cout << left << setw(39) << "" << "[4] Update Client.\n";
		cout << left << setw(39) << "" << "[5] Find Client.\n";
		cout << left << setw(39) << "" << "[6] Transactions.\n";
		cout << left << setw(39) << "" << "[7] Manage Users.\n";
		cout << left << setw(39) << "" << "[8] Login Registor.\n";
		cout << left << setw(39) << "" << "[9] Currency Exhange.\n";
		cout << left << setw(39) << "" << "[10] Logout.\n";
		cout << left << setw(37)  << ""<<"=========================================================\n";
		
		
		_PerformMainMenueOption((enMainMinue)_ReadMainMenue());
	}

};

