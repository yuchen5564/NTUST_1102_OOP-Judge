// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Use Babylonian algorithm to find the square root of a positive number.

#include <iostream>
using namespace std;

int main() {

	double num, nowGuess, lestGuess, temp;

	while (cin >> num) {
		//Set the initial value as num/2.
		nowGuess = num / 2.0;
		lestGuess = num; 

		//If lest guess minus now guess more then 0.01, do it again until it lower then 0.01.
		while (lestGuess - nowGuess > 0.01) {
			lestGuess = nowGuess;
			temp = num / nowGuess;
			nowGuess = (nowGuess + temp) / 2.0;
		}

		printf("%.2f\n", nowGuess);
	}
	
}