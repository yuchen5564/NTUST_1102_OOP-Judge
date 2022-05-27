// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 10, 2022
// Last Update: March, 10, 2022
// Problem statement: 輸入一個範圍，找到以3N+1規則進行運算最多次的數

#include <iostream>
using namespace std;

//計算運算次數
//  奇數：3N+1
//  偶數：N/2
//  重複計算至num == 1
int countN(int num) {
	int n = 0;
	while (!(num == 1)) {
		if (num % 2 == 0) num = num / 2;
		else num = 3 * num + 1;
		n++;
	}
	return n + 1;
}

int main() {
	int a, b, maxN, n;
	while (cin >> a >> b) {
		maxN = 0;
		cout << a << " " << b << " ";
		if (a > b) swap(a, b);	//確保a>b

		//在範圍內尋找運算次數最多的數
		for (int i = a; i <= b; i++) {
			n = countN(i);
			if (n > maxN) maxN = n;
		}
		cout << maxN << endl;
	}
	return 0;
}