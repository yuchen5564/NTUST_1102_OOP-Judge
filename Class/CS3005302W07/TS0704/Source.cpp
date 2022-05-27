// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 29, 2022
// Last Update: March, 29, 2022
// Problem statement: write a program to count Levenshtein Distance

#include <iostream>
#include <string>
using namespace std;

//return min number
int findMin(int a, int b, int c) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}

int main() {
	
	string a, b;
	while (getline(cin, a)) {
		getline(cin, b);
		int lenA = a.length();
		int lenB = b.length();

		//宣告&建立 二維動態陣列
		int** matrix = new int* [lenB + 1]; 
		for (int i = 0; i <= lenB; i++) {
			matrix[i] = new int[lenA + 1]{};
		}
		for (int i = 0; i <= lenA; i++) {
			matrix[0][i] = i;
		}
		for (int i = 0; i <= lenB; i++) {
			matrix[i][0] = i;
		}

		//利用萊文斯坦距離算出最小編輯次數
		int remove = 0; //刪除累積編輯距離+刪除成本 
		int insert = 0; //插入累積編輯距離+插入成本
		int replace = 0; //置換累積編輯距離+不相等時置換成本

		for (int i = 1; i <= lenB; i++) {
			for (int j = 1; j <= lenA; j++) {
				remove = matrix[i - 1][j] + 1;
				insert = matrix[i][j - 1] + 1;
				if (a[j - 1] != b[i - 1]) replace = matrix[i - 1][j - 1] + 1;
				else replace = matrix[i - 1][j - 1];
				matrix[i][j] = findMin(remove, insert, replace); //取出最小值，放入當前位置
			}
		}

		cout << matrix[lenB][lenA] << endl; //二維陣列右下即為最小編輯距離

		//釋放記憶體
		for (int i = 0; i <= lenB; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	
	return 0;
}