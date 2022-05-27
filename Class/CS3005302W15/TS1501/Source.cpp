// Name: ��౱�(Yu-chen Kuo)
// Date: May, 24, 2022
// Last Update: May, 27, 2022
// Problem statement: STL (vector�Bset�Bsort)


#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//���
bool compare(string a, string b) {
	if (a < b) return true;
	else return false;
}

int main() {
	fstream file;
	file.open("name.txt", ios::in); //read file
	vector<string> list;
	vector<string>::iterator i; //���N��
	set<string> check;
	string name;

	//get input
	while (getline(file, name)) {

		//�T�{�O�_����
		if (!check.count(name)) {
			list.push_back(name);
			check.insert(name);
		}

	}

	//sort
	sort(list.begin(), list.end(), compare);

	//output
	for (i = list.begin(); i != list.end(); i++) {
		cout << *i << "\n";
	}

	file.close();
	return 0;
}