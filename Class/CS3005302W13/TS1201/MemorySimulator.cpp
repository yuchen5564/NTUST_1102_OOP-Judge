// Name: 郭鈺晨(Yu-chen Kuo)
// Date: May, 10, 2022
// Last Update: May, 10, 2022
// Problem statement: simulator menory to store data

#include <iostream>
#include <string>
using namespace std;

//將command對應轉換成數字
int selectCommand(string command) {
	if (command == "Set") return 1;
	if (command == "Get") return 2;
}

//將type對應轉換成數字
int selectType(string type) {
	if (type == "char") return 1;
	if (type == "short") return 2;
	if (type == "int") return 3;
	if (type == "String") return 4;
}

/* 判斷流程：
*	1.判別Set、Get
*	2.判別Type
*	3.執行相對應動作
*/

int main() {
	char* menory;
	unsigned int totalSize, step, pos;
	string command, type;
	cin >> totalSize >> step;
	menory = new char[totalSize] {};

	for (int i = 0; i < step; i++) {
		cin >> command >> pos >> type;

		//out of range
		if (pos < 0 || pos > totalSize) {
			cout << "Violation Access." << endl;
			continue;
		}

		switch (selectCommand(command)) { //判斷command (1 = Set, 2 = Get)
		//Set============================================================================ 
		case 1: 
			switch (selectType(type)) { //判斷type (1: char, 2: short, 3: int, 4:String)
			//char
			case 1:
				unsigned int charIn;
				cin >> charIn;

				if (pos + 1 >= totalSize) {	
					cout << "Violation Access." << endl;
					memcpy(menory + pos, &charIn, totalSize - pos);
				}
				else memcpy(menory + pos, &charIn, 1);

				break;
			//short
			case 2:
				int shortIn;
				cin >> shortIn;

				if (pos + 2 > totalSize) {
					cout << "Violation Access." << endl;
					memcpy(menory + pos, &shortIn, totalSize - pos);
				}
				else memcpy(menory + pos, &shortIn, 2);

				break;
			//int
			case 3:
				unsigned int intIn;
				cin >> intIn;

				if (pos + 4 > totalSize) {
					cout << "Violation Access." << endl;
					memcpy(menory + pos, &intIn, totalSize - pos);
				}
				else memcpy(menory + pos, &intIn, 4);

				break;
			//string
			case 4:
				string stringIn;
				getchar();
				getline(cin, stringIn);

				if (pos + stringIn.size() >= totalSize) {
					cout << "Violation Access." << endl;
					memcpy(menory + pos, stringIn.c_str(), totalSize - pos);
				}
				else memcpy(menory + pos, stringIn.c_str(), stringIn.size());
				
				break;
			}
			break;
		//get============================================================================== 
		case 2: 
			switch (selectType(type)) { //判斷type (1: char, 2: short, 3: int, 4:String)
			//char
			case 1:
				unsigned char charOut;

				if (pos + 1 > totalSize) cout << "Violation Access." << endl;
				else {
					memcpy(&charOut, menory + pos, 1);
					cout << (int)charOut << endl;
				}

				break;
			//short
			case 2:
				int shortOut;

				if (pos + 2 > totalSize) cout << "Violation Access." << endl;
				else {
					memcpy(&shortOut, menory + pos, 2);
					cout << shortOut << endl;
				}

				break;
			//int
			case 3:
				unsigned int intOut;

				if (pos + 4 > totalSize) cout << "Violation Access." << endl;
				else {
					memcpy(&intOut, menory + pos, 4);
					cout << intOut << endl;
				}

				break;
			//string
			case 4:
				char* p = menory + pos;
				int i = pos;

				while (*p != '\0' && i < totalSize) {
					cout << (char)(*p);
					p++;
					i++;
				}

				cout << endl;
				break;
			}
			break;
		}
	}
	delete[] menory;
	return 0;
}
