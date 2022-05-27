// Name: ³¢à±±á(Yu-chen Kuo)
// Date: May, 03, 2022
// Last Update: May, 03, 2022
// Problem statement: Derived Class

#pragma once
#include "Document.h"
class File : public Document
{
public:
	File(string _text, string _path);
	
	//File& operator=(File f1);

	void setPathname(string _path);

	string getPathname();
private:
	string path;
};

