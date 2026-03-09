#pragma once
#include <iomanip>
#include "clsUsers.h"
#include "clsScreen.h"
#include "clsUtility.h"
class clsUserListScreen:protected clsScreen
{
private:
	static void _PrintUserRecordToLine(clsUsers User) {

		cout << setw(8) << left << "" << "| " << setw(16) << left<<User.UserName;
		cout << "| " << setw(22) << left << User.FullName();
		cout << "| " << setw(15) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(15) << left << User.Permition<< endl;
	}
public :
	static void ShowListUserScreen() {

		vector <clsUsers> vUser = clsUsers::GetUserList();

		
		string Title = "\tList User Screen";
		string subTitle =  "\t(" + to_string(vUser.size()) + ") User(s)";
		clsScreen::_DrawScreenHeader(Title, subTitle);
		
		cout <<"\n" << setw(8) << left << "" << "___________________________________________"
			"_____________________________________________________________\n";
		cout << setw(8) << left << "" << "| " << setw(16) << left << "UserName";
		cout << "| " << setw(22) << left << "FullName";
		cout << "| " << setw(15) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left  << "Password";
		cout << "| " << setw(12) << left << "Permission";
		cout << "\n" << setw(8) << left << "" << "____________________________________________"
			"_____________________________________________________________\n\n";
		if (vUser.size() == 0) {
			cout << "No User Avilabe In the System!";

		}
		else {
			for (clsUsers& u : vUser) {
				
				_PrintUserRecordToLine(u);

			}
			cout << setw(8) << left << "" << "____________________________________________________"
				"___________________________________________________\n";
		}
	}


};

