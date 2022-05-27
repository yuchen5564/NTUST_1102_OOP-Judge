// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Write a program to fill the space when input less than 10 digits.

#include <iostream>
using namespace std;

int main() {
	
	string num;
	while (cin >> num) {

		//Get the number of digits.
		int len = num.length();

		//Decide how many space need to print.
		if (len < 10) {
			for (int i = 0; i < 10 - len; i++) {
				cout << " ";
			}
		}

		cout << num << endl;
	}


}