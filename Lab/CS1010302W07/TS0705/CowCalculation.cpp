// Name: ³¢à±±á(Yu-chen Kuo)
// Date: March, 31, 2022
// Last Update: March, 31, 2022
// Problem statement: calculation cow

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//change char to number
string toNumber(string str) {
	string result = { };
	int len = str.length();
	for (int i = 0; i < len; i++) {
		switch(str[i]) {
		case'V':
			result += '0';
			break;
		case'U':
			result += '1';
			break;
		case'C':
			result += '2';
			break;
		case'D':
			result += '3';
			break;
		}
	}
	len = result.length();
	if (len < 8) {
		for (int i = 0; i < 8 - len; i++) {
			result = '0' + result;
		}
	}
	return result;
}

//add two cows
string add(string cow1, string cow2) {
	string result = {};
	int tmp, carry = 0;
	for (int i = 7; i >= 0; i--) {
		tmp = (cow1[i] - '0') + (cow2[i] - '0') + carry;
		if (tmp >= 4) {
			carry = 1;
			tmp -= 4;
		}
		else {
			carry = 0;
		}
		result = (char)(tmp + '0') + result;
	}
	if (carry == 1) result = '1' + result;
	
	return result;
}

int main() {
	string cow1, cow2, result;
	int num = 0;
	while (cin >> num) {
		cout << "COWCULATIONS OUTPUT\n";
		for (int k = 0; k < num; k++) {
			cin >> cow1 >> cow2;
			cow1 = toNumber(cow1);
			cow2 = toNumber(cow2);
			for (int i = 0; i < 3; i++) {
				char command;
				cin >> command;
				switch (command) {
				case'N': //no effect
					break;
				case'R': //move right
					for (int i = 7; i >= 1; i--) {
						cow2[i] = cow2[i - 1];
					}
					cow2[0] = '0';
					break;
				case'L': //move left
					for (int i = 0; i < 7; i++) {
						cow2[i] = cow2[i + 1];
					}
					cow2[7] = '0';
					break;
				case'A':
					cow2 = add(cow1, cow2);
					break;
				}
			}

			cin >> result;
			result = toNumber(result);
			//compare
			if (cow2 == result) cout << "YES\n";
			else cout << "NO\n";
		}
		cout << "END OF OUTPUT\n";
	}
	
	
	

	
	return 0;
}