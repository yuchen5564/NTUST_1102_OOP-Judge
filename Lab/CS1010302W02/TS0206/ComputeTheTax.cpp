// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February 24, 2022
// Last Update: February 24, 2022
// Problem statement: Write a program to count the tax.

#include <iostream>
using namespace std;

int main() {
	int income = 0;
	float tax = 0;
	while (cin >> income) {
		
		//use income to judge the tax
		if (income <= 750) tax = income * 0.01;
		else if (income > 750 && income <= 2250) tax = 7.50 + (income - 750) * 0.02;
		else if (income > 2250 && income <= 3750) tax = 37.50 + (income - 2250) * 0.03;
		else if (income > 3750 && income <= 5250) tax = 82.50 + (income - 3750) * 0.04;
		else if (income > 5250 && income <= 7000) tax = 142.50 + (income - 5250) * 0.05;
		else tax = 230.00 + (income - 7000) * 0.06;

		printf("%.2f\n", tax);
	}
}