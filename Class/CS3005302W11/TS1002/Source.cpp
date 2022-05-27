// Name: 郭鈺晨(Yu-chen Kuo)
// Date: April, 26, 2022
// Last Update: April, 26, 2022
// Problem statement: Use RECURSION to design a word game.

#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;


char grid[4][4]; //版面
int check[4][4] = { }; //紀錄是否走過
set<string> checkStr; //紀錄字串是否重複

//位置
typedef struct Position{
	int x = 0;
	int y = 0;
};

//檢查是否合法
bool checkValid(string s, Position pos, string str) {
	check[pos.y][pos.x] = 1;

	//如果長度為1
	if (s.length() == 1) {

		//檢查是否有重複字串
		if (!checkStr.count(str)) {
			cout << str << "\n"; //輸出
			checkStr.insert(str);
			return true; //回傳True
		}
		else {
			return true; //回傳True
		}

	}
	else {
		
		Position tmp = pos;
		char next = s[1];
		
		//遍歷四周，尋找下一點
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {

				if (pos.x + j >= 4 || pos.x + j < 0) continue;
				else tmp.x = pos.x + j;

				if (pos.y + i >= 4 || pos.y + i < 0) continue;
				else tmp.y = pos.y + i;

				//如果找到對應，且該格沒有走過
				if (grid[tmp.y][tmp.x] == next && check[tmp.y][tmp.x] != 1) {

					string sTmp = s;
					s.erase(0, 1);

					//檢查下一位字元
					if (checkValid(s, tmp, str)) return true; //檢查回傳值為True，回傳True
					else { //檢查回傳值為False，重設相關數據，繼續檢查
						s = sTmp;
						next = s[1];
						check[tmp.y][tmp.x] = 0;
					}

				}

			}
		}
		
	}
	return false; //未找到對應，回傳False
}

//重置檢查
void clearCheck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			check[i][j] = 0;
		}
	}
}

int main() {
	Position pos;
	fstream file;

	while (cin >> grid[0][0]) {
		file.open("words.txt", ios::in);
		checkStr.clear();

		//輸入版面
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == 0 && j == 0) continue;
				cin >> grid[i][j];
			}
		}

		string input;

		//接收檔案內容
		while (file >> input) {

			//尋找初始點
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					clearCheck(); //重置檢查

					if (grid[i][j] == input[0]) {
						pos.x = j;
						pos.y = i;
						checkValid(input, pos, input); //呼叫函式
					}

				}
			}

		}
		file.close();
	}
	return 0;
}