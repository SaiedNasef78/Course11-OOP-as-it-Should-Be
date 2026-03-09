#pragma once
#include <iostream>
#include <string>;
using namespace std;
class InterfaceCommunication
{
public:
	virtual void SendEmail(string Text, string body) = 0;
	virtual void SendFax(string Text, string body) = 0;
	virtual void SendSMS(string Text, string body) = 0;

};

