// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February 24, 2022
// Last Update: February 24, 2022
// Problem statement: Write a program to add two large numbers.

#include <iostream>
using namespace std;

typedef struct BigInt {
	string num;
};

//Intent: add two lager number
//Pre: the number is legal
//Post: return the number a+b
string Add(BigInt& a, BigInt& b) {
	//compare a's and b's length, if a's little than b's, swap two number.
	if (a.num.length() < b.num.length()) swap(a, b);
	int len = a.num.length(), lenB = b.num.length();
	int carry = 0, digit = 0;
	BigInt result;

	//add "0" to number b
	for (int i = 0; i < len - lenB; i++) b.num = "0" + b.num;
		
	//Add
	for (int i = len - 1; i >= 0; i--) {
		digit = (a.num[i]-'0') + (b.num[i]-'0') + carry;
		if (digit > 9) {
			carry = 1;
			digit = digit - 10;
		}
		else {
			carry = 0;
		}
		result.num = (char)(digit+'0') + result.num;
	}
	if(carry) result.num = "1" + result.num;
	return result.num;
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		BigInt a, b;
		bool notNum = false;
		cin >> a.num >> b.num;

		//judge the number legal or not
		for (int j = 0; j < a.num.length(); j++) {
			if (!isdigit(a.num[j])) {
				notNum = true;
				break;
			}
		}
		for (int j = 0; j < b.num.length(); j++) {
			if (!isdigit(b.num[j])) {
				notNum = true;
				break;
			}
		}
		
		//if number is illegal, print the error message
		if (notNum) {
			cout << "Not a valid number, please try again.\n";
			continue;
		}
		else {
			//call function
			cout << Add(a, b) << endl;
		}		
	}
}