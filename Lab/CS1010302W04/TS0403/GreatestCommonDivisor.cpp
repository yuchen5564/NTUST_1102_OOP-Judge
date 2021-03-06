// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 10, 2022
// Last Update: March, 10, 2022
// Problem statement: 輸入兩數，找到兩數的最大公因數(GCD)

#include <iostream>
using namespace std;

// 找出GCD
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