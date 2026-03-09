#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsers.h"
#include "clsSMainScreen.h"
#include "global.h"

class clsLoginScreen :protected clsScreen
{
private:
	
		static bool  _Login() {
		
				
				string UserName, Password;
				bool LoginFailed = false;
				short Trails = 3;
				do {
					if (LoginFailed) {
						
						cout << "\nInvalid UserName,Invalid Password";
						cout << "\nYou have " << --Trails << " Trials to login.\n\n";

					}
					if (Trails == 0) {
						cout << "You are locked after " << Trails << " faild trials\n";
					
						return false;
					}
					cout << "\nEnter UserName: ";
					cin >> UserName;
					cout << "\nEnter Password: ";
					cin >> Password;

					CurrentUser = clsUsers::Find(UserName, Password);
					
					LoginFailed = CurrentUser.IsEmpty();



				} while (LoginFailed);

				CurrentUser.LoginRegistor();
				clsSMainScreen::ShowMainMenue();
				return true;
			
	
		
		
		
		

	}

public:

	static bool  ShowLoginScreen() {
		system("cls");

		clsScreen::_DrawScreenHeader("Login Screen");
		
			return _Login();
		

		///*cout << "\nPlease Enter username ? \n";
		//string UserName = clsInputValidate::ReadString();

		//	cout << "\nPlease Enter Password? \n";
		//	string Password = clsInputValidate::ReadString();

		//	while (!clsUsers::IsUserExist(UserName, Password)) {

		//		cout << "\nPlease Enter username ? \n";
		//		 UserName = clsInputValidate::ReadString();

		//		cout << "\nPlease Enter Password? \n";
		//		 Password = clsInputValidate::ReadString();


		//	}*/



			

	}




};

