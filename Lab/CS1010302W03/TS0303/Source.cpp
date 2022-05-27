// Name: ��౱�(Yu-chen Kuo)
// Date: March, 4, 2022
// Last Update: March, 4, 2022
// Problem statement: Format input.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string x;
	int m, n;
	char c;
	int decimalPoint;
	int decimal, integer;
	
	while (cin >> x >> m >> n >> c) {
		int totalLen;

		//�M��p���I
		if (x.find('.') != string::npos) {
			decimalPoint = x.find('.') + 1;
			integer = decimalPoint - 1;
			decimal = x.length() - integer - 1;
		}
		else {
			if (n != 0) {
				x = x + '.';
			}
			decimalPoint = x.length();
			decimal = 0;
			integer = x.length();
			
		}

		//�p�Ƴ����榡��
		if (decimal > n) {
			x.erase(integer + 1 + n);
		}
		else {
			for (int i = 0; i < n - decimal; i++) {
				x = x + "0";
			}
		}
		if (n == 0) {
			if (x.find('.') != string::npos) {
				x.erase(x.find('.'));
			}
		}
		

		totalLen = x.length();

		//��Ƴ����榡��
		if (totalLen < m) {
			for (int i = 0; i < m - totalLen; i++) {
				x = c + x;
			}
		}
		cout << x << endl;
	}
	return 0;
}