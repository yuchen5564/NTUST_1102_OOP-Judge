// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February 24, 2022
// Last Update: February 24, 2022
// Problem statement: Write a program to format the data.

#include <iostream>
using namespace std;

int main() {
	int num = 0;
	string* name, * salary, * bonus;
	
	while (cin >> num) {
		/*
		* max1 = the maximum length of name
		* max2 = the maximum length of salary
		* max3 = the maximum length of bonus
		*/
		int max1 = 0, max2 = 0, max3 = 0;

		//allocate mamory for array
		name = new string[num];
		salary = new string[num];
		bonus = new string[num];

		//get input and count the width of each row
		for (int i = 0; i < num; i++) {
			cin >> *(name + i) >> *(salary + i) >> *(bonus + i);

			//if the length more then max, replace it
			if ((name + i)->length() > max1) max1 = (name + i)->length();
			if ((salary + i)->length() > max2) max2 = (salary + i)->length();
			if ((bonus + i)->length() > max3) max3 = (bonus + i)->length();
		}
		max2 += 2;
		max3 += 2;

		//print the data with format
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < max1 - (name + i)->length(); j++) {
				cout << " ";
			}
			cout << *(name + i) << "|";
			for (int j = 0; j < max2 - (salary + i)->length(); j++) {
				cout << " ";
			}
			cout << *(salary + i) << "|";
			for (int j = 0; j < max3 - (bonus + i)->length(); j++) {
				cout << " ";
			}
			cout << *(bonus + i) << endl;
		}

		//delete the memory
		delete[] name, salary, bonus;
	}
	
}