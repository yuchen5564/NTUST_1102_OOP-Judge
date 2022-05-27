// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February, 22, 2022
// Last Update: February, 22, 2022
// Problem statement: Write a program to count average and standard deviation

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double num = 0;
	double total = 0, average = 0;
	double sd = 0; //sd mean "standard deviation"

	while (cin >> num) {
		total = 0;
		average = 0;
		sd = 0;
		//allocate the memory for array
		double* arr;
		arr = new double[num];

		//get input and add total
		for (int i = 0; i < num; i++) {
			cin >> *(arr + i);
			total += *(arr + i);
		}

		//calculate the average
		average = total / num;

		//use formula to calculate the standard deviation
		for (int i = 0; i < num; i++) {
			sd += pow(*(arr + i) - average, 2.0);
		}
		sd = pow(sd / num, 0.5);

		cout << "Average:" << average << "\tStandard deviation:" << sd << endl;

		//delete the menory 
		delete[] arr;
		
	}	
}