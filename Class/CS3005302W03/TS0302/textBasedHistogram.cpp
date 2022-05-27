// Name: ��౱�(Yu-chen Kuo)
// Date: March, 1, 2022
// Last Update: March, 1, 2022
// Problem statement: Write a program to count the number.

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//�إ�struct
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
	vector<NumberList> list;	//�ϥ�vector�x�s�U�Ʀr�X�{���ƶq
	vector<NumberList>::iterator i;
	fstream outFile, inFile;	
	int num;
	inFile.open("grade.txt", ios::in);

	//��J�ôM��O�_���w�g�s�b��index�A�p�G�S���A�إ�index
	while (inFile >> num) {
		for (i = list.begin(); i != list.end(); i++) {
			if (num == i->index) {
				(i->count)++;
				break;
			}
		}
		if (i == list.end()) list.push_back({ num,1 });
	}

	//�̷�index�i��Ƨ�
	sort(list.begin(), list.end(), Compare);

	outFile.open("grades.Output", ios::out);

	int counter = 0; //������X����@�ӼƦr

	//��X
	for (i = list.begin(); i != list.end(); i++) {
		//�p�Gindex�S�������A��X"0 grade(s) of + index"
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