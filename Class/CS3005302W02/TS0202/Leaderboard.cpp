// Name: ³¢à±±á(Yu-chen Kuo)
// Date: February, 22, 2022
// Last Update: February, 24, 2022
// Problem statement: Write a program to find the top three.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//Intent: to find the high score
//Pre: input two list(name and score), and number of elements
//Post: return the list sort by score
void getHighScores(string* name, int* score, int n) {
	int temp = 0;
	string temp2;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (score[i] < score[j]) {
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
				temp2 = name[i];
				name[i] = name[j];
				name[j] = temp2;
			}
		}
	}
}

int main() {
	fstream file;
	string line, * name;
	int num = 0, * score;

	file.open("scores.txt", ios::in);
	while (getline(file, line)) {
		num++;
	}

	file.close();

	name = new string[num / 2];
	score = new int[num / 2];

	file.open("scores.txt", ios::in);
	for (int i = 0; i < num / 2; i++) {
		getline(file, *(name + i));
		getline(file, line);
		*(score + i) = stoi(line);
	}
	file.close();

	getHighScores(name, score, num / 2);

	for (int i = 0; i < 3; i++) {
		cout << *(name + i) << "\n" << *(score + i) << endl;
	}

}