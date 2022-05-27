// Name: ³¢à±±á(Yu-chen Kuo)
// Date: May, 03, 2022
// Last Update: May, 03, 2022
// Problem statement: Derived Class

#pragma once
#include "Document.h"
class Email : public Document
{
public:
	Email(string _text, string _sender, string _recipient, string _title);
	string getSender();
	string getRecipient();
	string getTitle();
private:
	string sender, recipient, title;
};

