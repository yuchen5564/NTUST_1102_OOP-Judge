// Name: 郭鈺晨(Yu-chen Kuo)
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

		//計算k值
		k = pow(2, 2 + distance / 10);

		int n = 0;
		double total = 0;
		//如果total小於k*log(2)，繼續運算
		while (total < k * log(2)) {
			n++;
			total += log(n);
		}
		cout << n - 1 << endl;

	}
	

	return 0;
}