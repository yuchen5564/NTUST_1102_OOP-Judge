// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 22, 2022
// Last Update: March, 22, 2022
// Problem statement: 數字遊戲，輸出list中，可由輸入數字組合整除的數

#include "NumberGame.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
using namespace std;

//設定數字
void NumberGame::SetInput(int a) {
	this->input = a;
}

//預處理，找出所有可被組合出的數(各位元相乘)
void NumberGame::ProcessInput() {
	int len = to_string(input).length(); //輸入數字之位元數
	int maxDigit = pow(2.0, (double)len); //可組合出數字之總數
	
	for (int i = 1; i < maxDigit; i++) {
		int sum = 1;
		bitset<32> digit(i); //以二進制挑選出需要相乘的數
		for (int j = 0; j < len; j++) {
			if (digit[j] == 1) { //如果被選中，相乘
				sum *= (to_string(input)[j] - '0');
			}
		}
		valid.push_back(sum); //放入vector中
	}
}

//設定list檔案名稱
void NumberGame::SetFileName(string a) {
	this->fileName = a;
}

//載入list內容
void NumberGame::LoadNumberList() {
	fstream file;
	file.open(this->fileName, ios::in);
	int num;
	vector<int>::iterator i;
	while (file >> num) {
		//如果與可被組合出之數字相同，放入vector中
		for (i = valid.begin(); i != valid.end(); i++) {
			if (*i == num) { 
				result.push_back(num);
				break;
			}
		}
	}
	file.close();
}

//輸出所有符合條件的數值
void NumberGame::PrintAllValid() {
	vector<int>::iterator i;
	for (i = result.begin(); i != result.end(); i++) {
		cout << *i << endl;
	}
}

void NumberGame::Reset() {
	valid.clear();
	result.clear();
}