// Name: ��౱�(Yu-chen Kuo)
// Date: March, 29, 2022
// Last Update: April, 5, 2022
// Problem statement: write a program which can slove Shisensho

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

typedef struct state {
	int x = 0; 
	int y = 0; 
	int turn = 0; //���s����
	int dir = 0; //��V
	int vIdx = 0; //�Ω���O�_�w�g�X�ݹL���I
	state(int _x = 0, int _y = 0, int _t = 0, int _d = 0, int _v = 0) : x(_x), y(_y), turn(_t), dir(_d), vIdx(_v) {};
};

int board[8][8] = { 0 };
int visit[8][8] = { 0 };
int directions[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

//�t��
bool match(int x1, int y1, int x2, int y2) {

	//�M�Ŭ�������
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			visit[i][j] = -1;
		}
	}

	//�W�X�d��
	if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) return false;

	//��m�۵�
	if (x1 == x2 && y1 == y2) return false;

	//��m�O�Ū�
	if (board[y1][x1] == 0 || board[y2][x2] == 0) return false;

	//�Ʀr���۵�
	if (board[y1][x1] != board[y2][x2]) return false;

	//���I�۳s
	if (x1 == x2 || y1 == y2) {
		if (abs(x1 - x2) == 1 || abs(y1 - y2) == 1) {
			board[y1][x1] = 0;
			board[y2][x2] = 0;
			return true;
		}
	}

	std::stack<state> pathStack;

	//�]�w�_�l�I
	pathStack.push(state(x1, y1, -1, -1));

	while (!pathStack.empty())
	{
		//���X���|�̤W�����I
		state s = pathStack.top();
		pathStack.pop();

		//�N���I�]���w�g�X�ݹL
		visit[s.y][s.x] = s.vIdx;

		//�M�X�|�Ӥ�V
		for (int d = 0; d < 4; d++) {
			int x = s.x + directions[d][0];
			int y = s.y + directions[d][1];

			//�p�����s����
			int turn = s.turn;
			if (s.dir != d) turn += 1;//�P���V���P

			if (turn < 3) {
				//�W�X����
				if (x < 0 || x > 7 || y < 0 || y > 7) continue;

				//���I���\�۳s
				if (x == x2 && y == y2) {
					//�������I(�]��0)
					board[y1][x1] = 0;
					board[y2][x2] = 0;
					return true;
				}

				//�����\�X�ݡA�B���I�Ÿ���0
				if ((visit[y][x] == -1 || visit[y][x] >= s.vIdx) && board[y][x] == 0) {
					//�]�w���U�@�ӳX���I
					pathStack.push(state(x, y, turn, d, s.vIdx + 1));
				}
			}
		}
	}

	//�����\�s�u
	return false;

}


int main() {

	int x1, y1, x2, y2;

	//��J����
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			cin >> board[i][j];
		}
	}

	while (cin >> x1 >> y1 >> x2 >> y2) {
		if (match(x1 + 1, y1 + 1, x2 + 1, y2 + 1)) {
			std::cout << "pair matched" << std::endl;
		}
		else {
			std::cout << "bad pair" << std::endl;
		}
	}

	return 0;
}