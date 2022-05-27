#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct {
	string name;
	int score;
}Data;

bool compare(Data a, Data b) {
	return a.score > b.score;
}

int main() {
	fstream file;
	file.open("scores.txt", ios::in);
	Data tmp;
	vector<Data> board;
	while (file>>tmp.name) {
		file >> tmp.score;
		board.push_back(tmp);
	}

	sort(board.begin(), board.end(), compare);

	for (int i = 0; i < 3; i++) {
		cout << board[i].name << "\n" << board[i].score << endl;
	}
	file.close();
	return 0;
}