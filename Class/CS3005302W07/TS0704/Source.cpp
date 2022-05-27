// Name: ��౱�(Yu-chen Kuo)
// Date: March, 29, 2022
// Last Update: March, 29, 2022
// Problem statement: write a program to count Levenshtein Distance

#include <iostream>
#include <string>
using namespace std;

//return min number
int findMin(int a, int b, int c) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}

int main() {
	
	string a, b;
	while (getline(cin, a)) {
		getline(cin, b);
		int lenA = a.length();
		int lenB = b.length();

		//�ŧi&�إ� �G���ʺA�}�C
		int** matrix = new int* [lenB + 1]; 
		for (int i = 0; i <= lenB; i++) {
			matrix[i] = new int[lenA + 1]{};
		}
		for (int i = 0; i <= lenA; i++) {
			matrix[0][i] = i;
		}
		for (int i = 0; i <= lenB; i++) {
			matrix[i][0] = i;
		}

		//�Q�εܤ崵�Z�Z����X�̤p�s�覸��
		int remove = 0; //�R���ֿn�s��Z��+�R������ 
		int insert = 0; //���J�ֿn�s��Z��+���J����
		int replace = 0; //�m���ֿn�s��Z��+���۵��ɸm������

		for (int i = 1; i <= lenB; i++) {
			for (int j = 1; j <= lenA; j++) {
				remove = matrix[i - 1][j] + 1;
				insert = matrix[i][j - 1] + 1;
				if (a[j - 1] != b[i - 1]) replace = matrix[i - 1][j - 1] + 1;
				else replace = matrix[i - 1][j - 1];
				matrix[i][j] = findMin(remove, insert, replace); //���X�̤p�ȡA��J��e��m
			}
		}

		cout << matrix[lenB][lenA] << endl; //�G���}�C�k�U�Y���̤p�s��Z��

		//����O����
		for (int i = 0; i <= lenB; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	
	return 0;
}