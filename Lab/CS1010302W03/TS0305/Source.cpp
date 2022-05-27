// Name: ��౱�(Yu-chen Kuo)
// Date: March, 4, 2022
// Last Update: March, 4, 2022
// Problem statement: Draw the graph.

#include <iostream>
using namespace std;

int main() {
	
	//���X���a
	int sizeX, sizeY;
	cin >> sizeX >> sizeY;
	char** figure;
	figure = new char* [sizeX];
	for (int i = 0; i < sizeX; i++) {
		figure[i] = new char[sizeY];
	}
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			figure[i][j] = '*';
		}
	}

	//�������w�Ϊ�
	string command;
	int x1, y1, x2, y2, w;
	string type;
	while (cin >> command) {
		if (command == "EXIT") break;

		//�e�����===========================================================
		if (command == "S") {
			cin >> w >> x1 >> y1;
			//�P�_�O�_�W�X�d��
			if (x1 > sizeX || y1 > sizeY || (x1 + w) > sizeX || (y1 + w) > sizeY) {//
				cout << "Out of range.\n\n";
				continue;
			}
			//���X�����
			for (int i = x1; i < x1 + w; i++) {
				for (int j = y1; j < y1 + w; j++) {
					figure[i][j] = 'X';
				}
			}
		}
		//===================================================================


		//�e���u==============================================================
		if (command == "L") {
			cin >> x1 >> y1 >> x2 >> y2;
			//�P�_�O�_�W�X�d��
			if (x1 > sizeX-1 || y1 > sizeY-1 || x2 > sizeX-1 || y2 > sizeY-1) {
				cout << "Out of range.\n\n";
				continue;
			}
			//���X���u
			if (x1 == x2) {
				if (y1 > y2) swap(y1, y2);
				for (int i = y1; i <= y2; i++) {
					figure[x1][i] = 'X';
				}
			}
			else if (y1 == y2) {
				if (x1 > x2) swap(x1, x2);
				for (int i = x1; i <= x2; i++) {
					figure[i][y1] = 'X';
				}
			}
			else if (x2 > x1) {
				if (y2 > y1) {
					for (int i = x1; i <= x2; i++) {
						figure[i][y1 + i] = 'X';
					}
				}
				else if (y1 > y2) {
					for (int i = x1; i <= x2; i++) {
						figure[i][y1 - i] = 'X';
					}
				}
				
			}
			else if (x1 > x2) {
				if (y1 > y2) {
					for (int i = x2; i <= x1; i++) {
						figure[i][y1 - i] = 'X';
					}
				}
				else if (y2 > y1) {
					for (int i = x2; i <= x1; i++) {
						figure[i][y1 + i] = 'X';
					}
				}
				
			}
		}
		//===================================================================
	
		//�e�T����===========================================================
		if (command == "T") {
			cin >> w >> x1 >> y1 >> type;
			//�P�_�O�_�W�X�d��
			if (x1 > sizeX || y1 > sizeY) {
				cout << "Out of range.\n\n";
				continue;
			}
			if (type == "LU") {
				//�P�_�O�_�W�X�d��
				if ((x1 - w) < 0 || (y1 - w) < 0) {
					cout << "Out of range.\n\n";
					continue;
				}
				//���X�T����
				for (int i = x1; i > x1 - w; i--) {
					for (int j = y1; j > y1 - w - (i - x1); j--) {
						figure[i][j] = 'X';
					}
				}
			}
			else if (type == "LD") {
				//�P�_�O�_�W�X�d��
				if ((x1 - w) < 0 || (y1 + w) > sizeY) {
					cout << "Out of range.\n\n";
					continue;
				}
				//���X�T����
				for (int i = x1; i > x1 - w; i--) {
					for (int j = y1; j < y1 + w - (x1 - i); j++) {
						figure[i][j] = 'X';
					}
				}
			}
			else if (type == "RU") {
				//�P�_�O�_�W�X�d��
				if ((x1 + w) > sizeX || (y1 - w) < 0) {
					cout << "Out of range.\n\n";
					continue;
				}
				//���X�T����
				for (int i = x1; i < x1 + w; i++) {
					for (int j = y1; j > y1 - w - (x1 - i); j--) {
						figure[i][j] = 'X';
					}
				}
			}
			else if (type == "RD") {
				//�P�_�O�_�W�X�d��
				if ((x1 + w) > sizeX || (y1 + w) > sizeY) {
					cout << "Out of range.\n\n";
					continue;
				}
				//���X�T����
				for (int i = x1; i < x1 + w; i++) {
					for (int j = y1; j < y1 + w - (i - x1); j++) {
						figure[i][j] = 'X';
					}
				}
			}
		}
		//===================================================================
		
		//output
		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				cout << figure[j][i];
			}
			cout << endl;
		}
		cout << endl;
	}

	
	

	return 0;
}