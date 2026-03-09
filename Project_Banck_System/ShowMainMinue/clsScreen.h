#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDate.h"
#include "clsUsers.h"
#include <iomanip>
#include "global.h"
using namespace std;
class clsScreen
{
private:
	static void _PrintDate() {
		cout << left << setw(48) << "" << "User: " << CurrentUser.UserName << "\n";
		
		cout << left << setw(48) << "" << "Date: " << clsDate::DateToString(clsDate ());
		cout << "\n\n";

	}
protected:
	
	
	static void _DrawScreenHeader(string Title,string subtitle="") {
		cout << left<<setw(37) << "" << "________________________________________________________\n\n";
		cout << left<<setw(50) <<"" << Title << endl<<endl;
		if (subtitle != "") {
			cout << left<< setw(50) << "" << subtitle << endl;
		}
		cout << left << setw(37) << "" << "________________________________________________________\n\n";

		_PrintDate();
	}
	static  bool CheckAccessRight(clsUsers::enPermissions Permission) {
	
		
		if (!CurrentUser.CheeckAccessPermissions(Permission))
		{
			cout << left << setw(37) << "" << "________________________________________________________\n\n";
			cout << left << setw(45) << "" << "AccessDenide! Contact your Admin\n\n";
			cout << left << setw(37) << "" << "________________________________________________________\n\n";
			return false;
	}
		else {
			return true;
		}
	}

};

