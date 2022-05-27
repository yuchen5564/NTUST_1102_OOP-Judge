// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 22, 2022
// Last Update: March, 22, 2022
// Problem statement: 尋找質數

#include "PrimeNumber.h"
#include <iostream>
using namespace std;

//檢查是否為質數
bool checkPrime(int num) {
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

//初始化(沒指定初始數值)
PrimeNumber::PrimeNumber() {
	value = 1;
}

//初始化(有指定初始數值)
PrimeNumber::PrimeNumber(int a) {
	value = a;
}

//回傳現在數值
int PrimeNumber::get() {
	return value;
}

//overloading, 取得下一位質數
//a++, 先傳值再++
PrimeNumber PrimeNumber::operator++(int) {
	PrimeNumber tmp;
	tmp = *this;
	value++;
	while (!checkPrime(value)) value++;
	return tmp;
}

//overloading, 取得上一位質數
//a--, 先傳值再--
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

//overloading, 取得下一位質數
//++a, 先++再傳值
PrimeNumber& PrimeNumber::operator++() {
	value++;
	while (!checkPrime(value)) value++;
	return *this;
}

//overloading, 取得上一位質數
//--a, 先--再傳值
PrimeNumber& PrimeNumber::operator--() {
	if (value == 2) {
		value = 1;
		return *this;
	}
	value--;
	while (!checkPrime(value)) value--;
	return *this;
}