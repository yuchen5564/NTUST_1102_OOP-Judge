// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 31, 2022
// Last Update: April, 5, 2022
// Problem statement: print seven segment

#include <iostream>
#include <string>
using namespace std;

//七段數字
const char digital[10][9][3] = {
{{ ' ','_',' ' }, { '|',' ','|' }, { '|','_','|' }} ,//0
{{ ' ',' ',' ' }, { ' ',' ','|' }, { ' ',' ','|' }} ,//1
{{ ' ','_',' ' }, { ' ','_','|' }, { '|','_',' ' }} ,//2
{{ ' ','_',' ' }, { ' ','_','|' }, { ' ','_','|' }} ,//3
{{ ' ',' ',' ' }, { '|','_','|' }, { ' ',' ','|' }} ,//4
{{ ' ','_',' ' }, { '|','_',' ' }, { ' ','_','|' }} ,//5
{{ ' ','_',' ' }, { '|','_',' ' }, { '|','_','|' }} ,//6
{{ ' ','_',' ' }, { ' ',' ','|' }, { ' ',' ','|' }} ,//7
{{ ' ','_',' ' }, { '|','_','|' }, { '|','_','|' }} ,//8
{{ ' ','_',' ' }, { '|','_','|' }, { ' ','_','|' }} ,  //9
};


int main() {
	string input;
	while (getline(cin,input)) {
		//去除非數字字元
		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				input.erase(input.begin() + i);
				i--;
			}
		}
		//輸出七段顯示
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < input.length(); j++) {
				for (int k = 0; k < 3; k++) {
					printf("%c", digital[input[j] - '0'][i][k]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}