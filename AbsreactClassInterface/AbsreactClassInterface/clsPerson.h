#pragma once
#include "InterfaceCommunication.h"
class clsPerson:public InterfaceCommunication
{
private:
	string _FirstNam;
	string _LastName;
	string _Email;
	string _Phone;

public:
	void SendEmail(string Text, string Boudy) {

	}
	void SendSMS(string Text, string Boudy) {

	}

	void SendFax(string Text, string body) {

	}

	void setFirstName(string FirstName) {
		_FirstNam = FirstName;

	}
	string GetFirstName() {
		return _FirstNam;
	}
	__declspec(property(get = GetFirstName,put = setFirstName)) string FirstName;
	void setLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = setLastName)) string LastName;


	void setEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	__declspec(property(get = GetEmail, put = setEmail)) string Email;

	void setPhone(string Phone) {
		_Phone = Phone;
	}
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = setPhone)) string Phone;
	
	string FullName() {
		return _FirstNam + " " + _LastName;
	}
};

