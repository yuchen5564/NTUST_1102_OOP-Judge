// Name: ��౱�(Yu-chen Kuo)
// Date: March, 29, 2022
// Last Update: March, 29, 2022
// Problem statement: define a class to chang array into integer

#include "Atoi.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//��l��(�L�Ѽ�)
Atoi::Atoi() {
	this->beTrans = {};
}

//��l��(���Ѽ�)
Atoi::Atoi(string s) {
	this->beTrans = s;
}

//�]�w�r��
void Atoi::SetString(string s) {
	this->beTrans = s;
}

//�^�Ǧr��
const string Atoi::GetString() {
	return this->beTrans;
}

//�^�Ǧr�����
int Atoi::Length() {
	int len = this->beTrans.length();
	if (beTrans[0] == '-') len--; //�t�����p�J����
	return len;
}

//�P�_�O�_���Ʀr
bool Atoi::IsDigital() {
	if (this->beTrans[0] == '-') { //�t��
		for (int i = 1; i < this->beTrans.length(); i++) {
			if (!isdigit(beTrans[i])) return false;
			else return true;
		}
	}
	else { //�D�t��
		for (int i = 0; i < this->beTrans.length(); i++) {
			if (!isdigit(beTrans[i])) return false;
			else return true;
		}
	}
}

//�ഫstring to integer
int Atoi::StringToInteger() {
	int num = 0;
	int len = this->beTrans.length();
	for (int i = 0; i < len;i++) {
		if (beTrans[len - i - 1] == '-') num = num * (-1);
		else num += (beTrans[len - i - 1] - '0') * pow(10, i);
	}
	return num;
}
