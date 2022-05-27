// Name: ��౱�(Yu-chen Kuo)
// Date: March, 4, 2022
// Last Update: March, 4, 2022
// Problem statement: Count the maximum amount the computer can store.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int year = 0;
	
	while (cin >> year) {
		int distance = year - 1900;
		int k = 4;

		//�p��k��
		k = pow(2, 2 + distance / 10);

		int n = 0;
		double total = 0;
		//�p�Gtotal�p��k*log(2)�A�~��B��
		while (total < k * log(2)) {
			n++;
			total += log(n);
		}
		cout << n - 1 << endl;

	}
	

	return 0;
}