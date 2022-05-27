// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Convert the format from seconds to hours-minutes-seconds.

#include <iostream>
using namespace std;

int main() {
	unsigned long long seconds = 0;
	unsigned long long hours = 0, minutes = 0;

	while (cin >> seconds) {

		//Convert seconds to hours and minutes.
		hours = seconds / 3600;
		seconds = seconds % 3600;
		minutes = seconds / 60;
		seconds = seconds % 60;

		cout << hours << " hours " << minutes << " minutes and " << seconds << " seconds" << endl;
	}
}