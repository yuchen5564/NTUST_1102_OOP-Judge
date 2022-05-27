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
	return a.index < b.index;
}

int main() {
	vector<NumberList> list;	//使用vector儲存各數字出現的數量
	vector<NumberList>::iterator i;
	fstream outFile, inFile;	
	int num;
	inFile.open("grade.txt", ios::in);

	//輸入並尋找是否有已經存在的index，如果沒有，建立index
	while (inFile >> num) {
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

	outFile.open("grades.Output", ios::out);

	int counter = 0; //紀錄輸出到哪一個數字

	//輸出
	for (i = list.begin(); i != list.end(); i++) {
		//如果index沒有紀錄，輸出"0 grade(s) of + index"
		while (counter != i->index) {
			outFile << "0 grade(s) of " << counter << endl;
			counter++;
		}
		outFile << i->count << " grade(s) of " << i->index << endl;
		counter++;
	}

	//close file
	outFile.close();
	inFile.close();
}