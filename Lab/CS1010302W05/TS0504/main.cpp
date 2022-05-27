// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 17, 2022
// Last Update: March, 17, 2022
// Problem statement: 輸入9x9數獨，判斷其是否合法

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main() {
	int sudoku[9][9]; //數獨盤面
	string input;
	char tmp;
	int count = 0;

	//input
	while (cin >> input) {
		count++;
		bool flag = true; //儲存是否合法
		for (int j = 0; j < 9; j++) {
			if (j != 0) cin >> input;
			for (int i = 0; i < input.length(); i++) {
				if (input[i] == '-') continue;
				else if (!isdigit(input[i])) {
					input[i] = ' ';
				}
			}
			istringstream in(input);
			for (int i = 0; i < 9; i++) {
				in >> sudoku[j][i];
				if (sudoku[j][i] > 9 || sudoku[j][i] < 1) flag = false; //數字不在1~9之內
			}
		}

		set<int> check; //設定一個set，用來檢查是否有數字重複

		//檢查行
		for (int i = 0; i < 9; ++i) {
			check.clear(); //清空set
			for (int j = 0; j < 9; ++j) {
				if (check.count(sudoku[j][i])) flag = false; //數字重複
				else check.insert(sudoku[j][i]); //數字未重複
			}
		}

		//檢查列
		for (int i = 0; i < 9; ++i) {
			check.clear(); //清空set
			for (int j = 0; j < 9; ++j) {
				if (check.count(sudoku[i][j])) flag = false; //數字重複
				else check.insert(sudoku[i][j]); //數字未重複
			}
		}

		//檢查3x3
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				check.clear(); //清空set
				for (int k = 0; k < 3; ++k) {
					for (int l = 0; l < 3; ++l) {
						if (check.count(sudoku[i * 3 + k][j * 3 + l])) flag = false; //數字重複
						else check.insert(sudoku[i * 3 + k][j * 3 + l]); //數字未重複
					}
				}
			}
		}

		if (!flag) cout << "False\n";
		else cout << "True\n";

	}
	
	return 0;
}