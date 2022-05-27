// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 31, 2022
// Last Update: March, 31, 2022
// Problem statement: design a class to slove the form game.

#include "Form.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

//設定單字
void Form::SetInputWord(string str) {
	this->inputWord = str;
}

//解析單字
void Form::ProcessInputWord() {
	int len = inputWord.length();
	for (int i = 0; i < len; i++) {
		if (isupper(inputWord[i])) inputWord[i] += 32;
	}
}

//設定list檔案名稱
void Form::SetFileName(string str) {
	this->fileName = str;
}

//比較list中的單字是否合法
void Form::Load_CompareWord() {
	fstream file;
	file.open(this->fileName, ios::in);
	string tmp;
	int wordCharacter[26] = {0};
	
	int len = inputWord.length();

	for (int i = 0; i < len; i++) {
		wordCharacter[inputWord[i] - 'a']++;
	}
	while (file >> tmp) {
		bool flag = true;
		int fileCharacter[26] = { 0 };
		for (int i = 0; i < tmp.length(); i++) {
			fileCharacter[tmp[i] - 'a']++;
			
		}
		for (int i = 0; i < 26; i++) {
			if (fileCharacter[i] > wordCharacter[i]) {
				flag = false;
				break;
			}
		}
		if (flag) { found.push_back(tmp); }
	}
}

//輸出合法單字
void Form::PrintFoundWords() {
	vector<string>::iterator i;
	for (i = found.begin(); i != found.end(); i++) {
		cout << *i << endl;
	}
}


