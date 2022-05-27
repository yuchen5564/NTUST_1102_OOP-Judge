// Name: ��౱�(Yu-chen Kuo)
// Date: March, 10, 2022
// Last Update: March, 10, 2022
// Problem statement: ��J��ơA����ƪ��̤j���]��(GCD)

#include <iostream>
using namespace std;

// ��XGCD
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