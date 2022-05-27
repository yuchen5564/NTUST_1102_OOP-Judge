// Name: 尝啾贬(Yu-chen Kuo)
// Date: March, 10, 2022
// Last Update: March, 10, 2022
// Problem statement: 块ㄢ计тㄢ计程そ计(GCD)

#include <iostream>
using namespace std;

// тGCD
int gcd(int n, int m) {
	if (m == 0) return n;
	else return gcd(m, n % m);
}

int main() {
	int a, b;

	//input
	while (cin >> a >> b) {
		cout << gcd(a, b) << endl;

	}

	return 0;
}