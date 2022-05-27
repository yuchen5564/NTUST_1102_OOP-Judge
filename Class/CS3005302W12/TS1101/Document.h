// Name: ³¢à±±á(Yu-chen Kuo)
// Date: May, 03, 2022
// Last Update: May, 03, 2022
// Problem statement: Base Class

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Document
{
public:
	Document(const char* _text);
	Document(string _text);
	Document& operator= (Document* in);
	const string getText() const;
private:
	string text;
};

