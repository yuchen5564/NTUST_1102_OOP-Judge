// Name: ��౱�(Yu-chen Kuo)
// Date: March, 17, 2022
// Last Update: March, 17, 2022
// Problem statement: ��J9x9�ƿW�A�P�_��O�_�X�k

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main() {
	int sudoku[9][9]; //�ƿW�L��
	string input;
	char tmp;
	int count = 0;

	//input
	while (cin >> input) {
		count++;
		bool flag = true; //�x�s�O�_�X�k
		for (int j = 0; j < 9; j++) {
			if (j != 0) cin >> input;
			for (int i = 0; i < input.length(); i++) {
				if (input[i] == '-') continue;
				else if (!isdigit(input[i])) {
					input[i] = ' ';
				}
			}
			istringstream in(input);
			for (int i = 0; i < 9; i++) {
				in >> sudoku[j][i];
				if (sudoku[j][i] > 9 || sudoku[j][i] < 1) flag = false; //�Ʀr���b1~9����
			}
		}

		set<int> check; //�]�w�@��set�A�Ψ��ˬd�O�_���Ʀr����

		//�ˬd��
		for (int i = 0; i < 9; ++i) {
			check.clear(); //�M��set
			for (int j = 0; j < 9; ++j) {
				if (check.count(sudoku[j][i])) flag = false; //�Ʀr����
				else check.insert(sudoku[j][i]); //�Ʀr������
			}
		}

		//�ˬd�C
		for (int i = 0; i < 9; ++i) {
			check.clear(); //�M��set
			for (int j = 0; j < 9; ++j) {
				if (check.count(sudoku[i][j])) flag = false; //�Ʀr����
				else check.insert(sudoku[i][j]); //�Ʀr������
			}
		}

		//�ˬd3x3
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				check.clear(); //�M��set
				for (int k = 0; k < 3; ++k) {
					for (int l = 0; l < 3; ++l) {
						if (check.count(sudoku[i * 3 + k][j * 3 + l])) flag = false; //�Ʀr����
						else check.insert(sudoku[i * 3 + k][j * 3 + l]); //�Ʀr������
					}
				}
			}
		}

		if (!flag) cout << "False\n";
		else cout << "True\n";

	}
	
	return 0;
}