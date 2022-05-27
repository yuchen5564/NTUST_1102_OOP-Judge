// Name: ��౱�(Yu-chen Kuo)
// Date: March, 10, 2022
// Last Update: March, 10, 2022
// Problem statement: ��J�@�ӽd��A���H3N+1�W�h�i��B��̦h������

#include <iostream>
using namespace std;

//�p��B�⦸��
//  �_�ơG3N+1
//  ���ơGN/2
//  ���ƭp���num == 1
int countN(int num) {
	int n = 0;
	while (!(num == 1)) {
		if (num % 2 == 0) num = num / 2;
		else num = 3 * num + 1;
		n++;
	}
	return n + 1;
}

int main() {
	int a, b, maxN, n;
	while (cin >> a >> b) {
		maxN = 0;
		cout << a << " " << b << " ";
		if (a > b) swap(a, b);	//�T�Oa>b

		//�b�d�򤺴M��B�⦸�Ƴ̦h����
		for (int i = a; i <= b; i++) {
			n = countN(i);
			if (n > maxN) maxN = n;
		}
		cout << maxN << endl;
	}
	return 0;
}