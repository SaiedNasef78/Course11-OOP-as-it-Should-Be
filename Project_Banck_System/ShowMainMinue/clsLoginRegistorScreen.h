#pragma once

#include "clsScreen.h"
#include "global.h"
#include <iomanip>
#include "clsUsers.h"
#include "clsUtility.h"
class clsLoginRegistorScreen:protected clsScreen
{
private:
	
 static void _PrintLoginFile(clsUsers::stLoginRegistor sLogin) {
	 
	 cout << "| " << left << setw(30) << sLogin.DateAndTime;

	 cout << "| " << left << setw(25) << sLogin.UserName;
	 cout << "| " << left << setw(25) << clsUtility::DecryptionText(sLogin.Password);
	 cout << "| " << left << setw(15) << sLogin.Permissions ;


	}



public:
	static void ShowLoginScreen() {

		if (!CheckAccessRight(clsUsers::enPermissions::pLoginRegistor)) {
			return; //this will exit the function 


		}


		vector <clsUsers::stLoginRegistor> vReg = clsUsers::GetLoginRegistor();

		string Title = "Login Registor List Screen";
		string subtitle = "(" + to_string(vReg.size()) + ") Record(s).";
		clsScreen::_DrawScreenHeader(Title, subtitle);
		 
		cout  << "\n\n" <<left << setw(8) << "" << "__________________________"
			"_______________________________________________________________________________\n\n";
		cout << left << setw(8) << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(25) << "UserName";
		cout << "| " << left << setw(25) << "Password";
		cout << "| " << left << setw(15) << "Permissions\n";

		cout << left << setw(5) << "" << "__________________________"
			"________________________________________________________________________________\n";

		if (vReg.size() == 0) {

			cout << "\t\t\t No LoginRegistor File Avilable In The System!";
		}
		else {
			for (clsUsers::stLoginRegistor& R : vReg) {

				cout << left << setw(8) << "";
				_PrintLoginFile(R);
				cout << "\n";
			}
			cout << left << setw(7) << "" << "__________________________"
				"________________________________________________________________________________\n";
		}
	}

};

