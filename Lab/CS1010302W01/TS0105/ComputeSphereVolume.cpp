// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Calculate the volume of a sphere with radius r. 


#include <iostream>
#define PI 3.14159265358979323846
using namespace std;

int main() {
	long double radius, volume;

	while (cin >> radius) {
		//Calculate volume by formula v=4/3*PI*r^3
		volume = 4.0 / 3 * PI * radius * radius * radius;
		printf("%.6f\n", volume);
	}
}