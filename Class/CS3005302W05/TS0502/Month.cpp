// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 15, 2022
// Last Update: March, 15, 2022
// Problem statement: 撰寫Class，可以記錄月份

#include <iostream>
#include <string>
#include "Month.h"
using namespace std;

//無參數初始化，預設一月
Month::Month() {
	monthInt = 1;
	monthStr = month[0];
}

//接收月份縮寫初始化
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

	//如果輸入不合法，設定為一月
	if (monthInt == 0) {
		monthInt = 1;
		monthStr = month[0];
	}
}

//接收月份數字初始化
Month::Month(int monthInt1) {
	if (monthInt1 < 1 || monthInt1>12) monthInt = 1; //如果輸入不合法，設定為一月
	else monthInt = monthInt1;

	monthStr = month[monthInt - 1];
}

//輸出月份數字
void Month::outputInt() {
	cout << monthInt;
}

//輸出月份縮寫
void Month::outputStr() {
	cout << monthStr;
}

//切換為下一個月
Month Month::nextMonth() {
	if (monthInt > 12) return 1;	//如果超過12月，設定為一月
	else return monthInt+1;
}

//接收輸入月份數字
void Month::inputInt() {
	cin >> monthInt;

	//如輸入不合法，設定為一月
	if (monthInt < 1 || monthInt > 12) monthInt = 1;
	monthStr = month[monthInt - 1];
}

//接收輸入月份縮寫
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

	//如果輸入不合法，設定為一月
	if (monthInt == 0) {
		monthInt = 1;
		monthStr = month[0];
	}
}

