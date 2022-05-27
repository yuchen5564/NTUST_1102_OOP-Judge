// Name: 郭鈺晨(Yu-chen Kuo)
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
	int turn = 0; //轉彎次數
	int dir = 0; //方向
	int vIdx = 0; //用於比對是否已經訪問過該點
	state(int _x = 0, int _y = 0, int _t = 0, int _d = 0, int _v = 0) : x(_x), y(_y), turn(_t), dir(_d), vIdx(_v) {};
};

int board[8][8] = { 0 };
int visit[8][8] = { 0 };
int directions[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

//配對
bool match(int x1, int y1, int x2, int y2) {

	//清空紀錄版面
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			visit[i][j] = -1;
		}
	}

	//超出範圍
	if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) return false;

	//位置相等
	if (x1 == x2 && y1 == y2) return false;

	//位置是空的
	if (board[y1][x1] == 0 || board[y2][x2] == 0) return false;

	//數字不相等
	if (board[y1][x1] != board[y2][x2]) return false;

	//兩點相連
	if (x1 == x2 || y1 == y2) {
		if (abs(x1 - x2) == 1 || abs(y1 - y2) == 1) {
			board[y1][x1] = 0;
			board[y2][x2] = 0;
			return true;
		}
	}

	std::stack<state> pathStack;

	//設定起始點
	pathStack.push(state(x1, y1, -1, -1));

	while (!pathStack.empty())
	{
		//取出堆疊最上面那點
		state s = pathStack.top();
		pathStack.pop();

		//將此點設維已經訪問過
		visit[s.y][s.x] = s.vIdx;

		//尋訪四個方向
		for (int d = 0; d < 4; d++) {
			int x = s.x + directions[d][0];
			int y = s.y + directions[d][1];

			//計算轉彎次數
			int turn = s.turn;
			if (s.dir != d) turn += 1;//與原方向不同

			if (turn < 3) {
				//超出版面
				if (x < 0 || x > 7 || y < 0 || y > 7) continue;

				//兩點成功相連
				if (x == x2 && y == y2) {
					//移除兩點(設為0)
					board[y1][x1] = 0;
					board[y2][x2] = 0;
					return true;
				}

				//未成功訪問，且該點符號為0
				if ((visit[y][x] == -1 || visit[y][x] >= s.vIdx) && board[y][x] == 0) {
					//設定為下一個訪問點
					pathStack.push(state(x, y, turn, d, s.vIdx + 1));
				}
			}
		}
	}

	//未成功連線
	return false;

}


int main() {

	int x1, y1, x2, y2;

	//輸入版面
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