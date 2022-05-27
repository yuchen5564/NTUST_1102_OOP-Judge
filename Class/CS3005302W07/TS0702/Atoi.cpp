// Name: 尝啾贬(Yu-chen Kuo)
// Date: March, 29, 2022
// Last Update: March, 29, 2022
// Problem statement: define a class to chang array into integer

#include "Atoi.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//﹍て(礚把计)
Atoi::Atoi() {
	this->beTrans = {};
}

//﹍て(Τ把计)
Atoi::Atoi(string s) {
	this->beTrans = s;
}

//砞﹚﹃
void Atoi::SetString(string s) {
	this->beTrans = s;
}

//肚﹃
const string Atoi::GetString() {
	return this->beTrans;
}

//肚﹃
int Atoi::Length() {
	int len = this->beTrans.length();
	if (beTrans[0] == '-') len--; //璽腹ぃ璸
	return len;
}

//耞琌计
bool Atoi::IsDigital() {
	if (this->beTrans[0] == '-') { //璽计
		for (int i = 1; i < this->beTrans.length(); i++) {
			if (!isdigit(beTrans[i])) return false;
			else return true;
		}
	}
	else { //獶璽计
		for (int i = 0; i < this->beTrans.length(); i++) {
			if (!isdigit(beTrans[i])) return false;
			else return true;
		}
	}
}

//锣传string to integer
int Atoi::StringToInteger() {
	int num = 0;
	int len = this->beTrans.length();
	for (int i = 0; i < len;i++) {
		if (beTrans[len - i - 1] == '-') num = num * (-1);
		else num += (beTrans[len - i - 1] - '0') * pow(10, i);
	}
	return num;
}
