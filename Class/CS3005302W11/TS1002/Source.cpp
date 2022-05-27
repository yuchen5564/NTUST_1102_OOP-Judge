// Name: ��౱�(Yu-chen Kuo)
// Date: April, 26, 2022
// Last Update: April, 26, 2022
// Problem statement: Use RECURSION to design a word game.

#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;


char grid[4][4]; //����
int check[4][4] = { }; //�����O�_���L
set<string> checkStr; //�����r��O�_����

//��m
typedef struct Position{
	int x = 0;
	int y = 0;
};

//�ˬd�O�_�X�k
bool checkValid(string s, Position pos, string str) {
	check[pos.y][pos.x] = 1;

	//�p�G���׬�1
	if (s.length() == 1) {

		//�ˬd�O�_�����Ʀr��
		if (!checkStr.count(str)) {
			cout << str << "\n"; //��X
			checkStr.insert(str);
			return true; //�^��True
		}
		else {
			return true; //�^��True
		}

	}
	else {
		
		Position tmp = pos;
		char next = s[1];
		
		//�M���|�P�A�M��U�@�I
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {

				if (pos.x + j >= 4 || pos.x + j < 0) continue;
				else tmp.x = pos.x + j;

				if (pos.y + i >= 4 || pos.y + i < 0) continue;
				else tmp.y = pos.y + i;

				//�p�G�������A�B�Ӯ�S�����L
				if (grid[tmp.y][tmp.x] == next && check[tmp.y][tmp.x] != 1) {

					string sTmp = s;
					s.erase(0, 1);

					//�ˬd�U�@��r��
					if (checkValid(s, tmp, str)) return true; //�ˬd�^�ǭȬ�True�A�^��True
					else { //�ˬd�^�ǭȬ�False�A���]�����ƾڡA�~���ˬd
						s = sTmp;
						next = s[1];
						check[tmp.y][tmp.x] = 0;
					}

				}

			}
		}
		
	}
	return false; //���������A�^��False
}

//���m�ˬd
void clearCheck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			check[i][j] = 0;
		}
	}
}

int main() {
	Position pos;
	fstream file;

	while (cin >> grid[0][0]) {
		file.open("words.txt", ios::in);
		checkStr.clear();

		//��J����
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == 0 && j == 0) continue;
				cin >> grid[i][j];
			}
		}

		string input;

		//�����ɮפ��e
		while (file >> input) {

			//�M���l�I
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					clearCheck(); //���m�ˬd

					if (grid[i][j] == input[0]) {
						pos.x = j;
						pos.y = i;
						checkValid(input, pos, input); //�I�s�禡
					}

				}
			}

		}
		file.close();
	}
	return 0;
}