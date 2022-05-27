// Name: ��౱�(Yu-chen Kuo)
// Date: March, 22, 2022
// Last Update: March, 22, 2022
// Problem statement: �M����

#include "PrimeNumber.h"
#include <iostream>
using namespace std;

//�ˬd�O�_�����
bool checkPrime(int num) {
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

//��l��(�S���w��l�ƭ�)
PrimeNumber::PrimeNumber() {
	value = 1;
}

//��l��(�����w��l�ƭ�)
PrimeNumber::PrimeNumber(int a) {
	value = a;
}

//�^�ǲ{�b�ƭ�
int PrimeNumber::get() {
	return value;
}

//overloading, ���o�U�@����
//a++, ���ǭȦA++
PrimeNumber PrimeNumber::operator++(int) {
	PrimeNumber tmp;
	tmp = *this;
	value++;
	while (!checkPrime(value)) value++;
	return tmp;
}

//overloading, ���o�W�@����
//a--, ���ǭȦA--
PrimeNumber PrimeNumber::operator--(int) {
	PrimeNumber tmp;
	tmp = *this;
	if (value == 2) {
		tmp.value = 1;
		return tmp;
	}
	value--;
	while (!checkPrime(value)) value--;
	return tmp;
}

//overloading, ���o�U�@����
//++a, ��++�A�ǭ�
PrimeNumber& PrimeNumber::operator++() {
	value++;
	while (!checkPrime(value)) value++;
	return *this;
}

//overloading, ���o�W�@����
//--a, ��--�A�ǭ�
PrimeNumber& PrimeNumber::operator--() {
	if (value == 2) {
		value = 1;
		return *this;
	}
	value--;
	while (!checkPrime(value)) value--;
	return *this;
}