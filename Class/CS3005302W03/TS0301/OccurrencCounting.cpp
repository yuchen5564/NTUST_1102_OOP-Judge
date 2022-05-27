// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 1, 2022
// Last Update: March, 1, 2022
// Problem statement: Write a program to count the number.

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//建立struct
typedef struct NumberList {
	int index;
	int count;
};


//Intent: compare the number 
//Pre: input two struct
//Po: return the result
bool Compare(NumberList a, NumberList b) {
	return a.index > b.index;
}

int main() {
	vector<NumberList> list;	//使用vector儲存各數字出現的數量
	vector<NumberList>::iterator i = list.begin(); //迭代器
	int num = 0;

	//接收輸入
	while (cin >> num) {
		for (i = list.begin(); i != list.end(); i++) {
			if (num == i->index) {
				(i->count)++;
				break;
			}
		}
		if (i == list.end()) list.push_back({ num,1 });
	}

	//依照index進行排序
	sort(list.begin(), list.end(), Compare);

	//output
	cout << "N\tcount\n";
	for (i = list.begin(); i != list.end(); i++) {
		cout << i->index << "\t" << i->count << endl;
	}
}