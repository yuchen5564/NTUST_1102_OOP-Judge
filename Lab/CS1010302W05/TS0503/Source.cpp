// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 17, 2022
// Last Update: March, 18, 2022
// Problem statement: 可以記錄學生資料

#include <iostream>
#include <vector>
using namespace std;

//定義struct
typedef struct {
	string firstName;
	string lastName;
	string phone;
} StRec;

//overloading，比較兩個StRec是否相同
bool operator==(StRec a, StRec b) {
	if (a.firstName == b.firstName && a.lastName == b.lastName && a.phone == b.phone) return true;
	else return false;
}

//檢查電話號碼是否合法
bool checkPhone(string phone) {
	int len = phone.length();
	for (int i = 0; i < len; i++) {
		if (!isdigit(phone[i])) return false; //含有非數字字元
	}
	if (phone[0] != '0') {
		if ((phone[0] == '8' && phone[1] == '8' && phone[2] == '6')) return true; //886開頭 -> 合法
	}
	else if (phone[0] != '0' || phone[1] == '0' || phone[1] == '1') return false; //00開頭 -> 不合法
	return true;
}

//檢查是否重複
bool checkRepeat(vector<StRec> record, StRec input) {
	vector<StRec>::iterator i;
	for (i = record.begin(); i < record.end(); i++) {
		if (input == *i) return true;
	}
	return false;
}

//檢查長度是否合法
bool checkLength(StRec tmp) {
	if (tmp.firstName.length() >= 25 || tmp.lastName.length() >= 30 || tmp.phone.length() >= 15) {
		return true;
	}
	return false;
}

//接收資料輸入
void getData(StRec* record) {
	cin >> record->firstName >> record->lastName >> record->phone;
}

int main() {
	vector<StRec> record;
	vector<StRec>::iterator i;
	StRec tmp;
	string command;

	while (cin >> command) {
		if (command == "print") { //commamd = print
			//沒有資料
			if (record.empty()) cout << "Print Error\n";
			else {
				for (i = record.begin(); i != record.end(); i++) {
					cout << i->firstName << " " << i->lastName << " " << i->phone << endl;
				}
			}
		}
		else if (command == "insert") { //command = insert
			getData(&tmp);
			//長度檢查
			if (checkLength(tmp)) {
				cout << "Input Error\n";
			}
			//資料數量
			else if (record.size() >= 10) {
				cout << "Insert Error\n";
			}
			//重複檢查
			else if (checkRepeat(record, tmp)) {
				cout << "Insert Error\n";
			}			
			//電話錯誤
			else if (!checkPhone(tmp.phone)) {
				cout << "Insert Error\n";
			}
			else {
				record.push_back(tmp);
			}
		}
		else if (command == "search") { //command = search
			int index = 0;
			bool flag = true; //紀錄是否找到資料
			getData(&tmp);
			//長度檢查
			if (checkLength(tmp)) {
				cout << "Input Error\n";
			}
			else {
				for (i = record.begin(); i != record.end(); i++) {
					if (tmp == *i) {
						cout << index << endl;
						flag = false;
						break;
					}
					else {
						index++;
					}
				}
				//找不到資料
				if (flag) cout << "Search Error\n";
			}
		}
		else if (command == "delete") { //command = delete
			bool flag = true; //紀錄是否找到資料
			getData(&tmp);
			//長度檢查
			if (checkLength(tmp)) {
				cout << "Input Error\n";
			}
			else {
				for (i = record.begin(); i != record.end(); i++) {
					if (tmp == *i) {
						record.erase(i);
						flag = false;
						break;
					}
				}
				//找不到資料
				if (flag) cout << "Delete Error\n";
			}
		}
		else {	//command not found
			getData(&tmp);
			cout << "Input Error\n";
		}
	}
	

	return 0;
}