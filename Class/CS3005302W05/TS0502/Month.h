#pragma once
#include <iostream>
using namespace std;

class Month {
public:
	Month(); //�L�Ѽƪ�l��
	Month(char first, char second, char third); //��������Y�g��l��
	Month(int monthInt1); //��������Ʀr��l��
	void inputInt(); //������J����Ʀr
	void inputStr(); //������J����Y�g
	void outputInt(); //��X����Ʀr
	void outputStr(); //��X����Y�g
	Month nextMonth(); //�������U�@�Ӥ�
private:
	string month[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	int monthInt = 0;
	string monthStr;
};
