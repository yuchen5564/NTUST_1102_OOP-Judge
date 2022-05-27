#pragma once
#include <iostream>
using namespace std;

class Month {
public:
	Month(); //無參數初始化
	Month(char first, char second, char third); //接收月份縮寫初始化
	Month(int monthInt1); //接收月份數字初始化
	void inputInt(); //接收輸入月份數字
	void inputStr(); //接收輸入月份縮寫
	void outputInt(); //輸出月份數字
	void outputStr(); //輸出月份縮寫
	Month nextMonth(); //切換為下一個月
private:
	string month[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	int monthInt = 0;
	string monthStr;
};
