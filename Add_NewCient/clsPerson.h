#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public :
	clsPerson(string firstName, string LastName, string Email, string Phone) {
		_FirstName = firstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	}
	void setFirstName(string firstName) {
		_FirstName = firstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;

	void setLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = setLastName)) string LastName;
	void setEmail(string email) {
		_Email = email;
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
		return _FirstName + " " + _LastName;
}
};

