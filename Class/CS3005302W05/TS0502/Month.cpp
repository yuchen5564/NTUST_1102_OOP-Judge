// Name: ��౱�(Yu-chen Kuo)
// Date: March, 15, 2022
// Last Update: March, 15, 2022
// Problem statement: ���gClass�A�i�H�O�����

#include <iostream>
#include <string>
#include "Month.h"
using namespace std;

//�L�Ѽƪ�l�ơA�w�]�@��
Month::Month() {
	monthInt = 1;
	monthStr = month[0];
}

//��������Y�g��l��
Month::Month(char first, char second, char third) {
	monthStr = third;
	monthStr = second + monthStr;
	monthStr = first + monthStr;

	for (int i = 0; i < 12; i++) {
		if (monthStr == month[i]) {
			monthInt = i + 1;
			break;
		}
	}

	//�p�G��J���X�k�A�]�w���@��
	if (monthInt == 0) {
		monthInt = 1;
		monthStr = month[0];
	}
}

//��������Ʀr��l��
Month::Month(int monthInt1) {
	if (monthInt1 < 1 || monthInt1>12) monthInt = 1; //�p�G��J���X�k�A�]�w���@��
	else monthInt = monthInt1;

	monthStr = month[monthInt - 1];
}

//��X����Ʀr
void Month::outputInt() {
	cout << monthInt;
}

//��X����Y�g
void Month::outputStr() {
	cout << monthStr;
}

//�������U�@�Ӥ�
Month Month::nextMonth() {
	if (monthInt > 12) return 1;	//�p�G�W�L12��A�]�w���@��
	else return monthInt+1;
}

//������J����Ʀr
void Month::inputInt() {
	cin >> monthInt;

	//�p��J���X�k�A�]�w���@��
	if (monthInt < 1 || monthInt > 12) monthInt = 1;
	monthStr = month[monthInt - 1];
}

//������J����Y�g
void Month::inputStr() {
	char first, second, third;
	cin >> first >> second >> third;
	monthStr = third;
	monthStr = second + monthStr;
	monthStr = first + monthStr;

	for (int i = 0; i < 12; i++) {
		if (monthStr == month[i]) {
			monthInt = i + 1;
			break;
		}
	}

	//�p�G��J���X�k�A�]�w���@��
	if (monthInt == 0) {
		monthInt = 1;
		monthStr = month[0];
	}
}

