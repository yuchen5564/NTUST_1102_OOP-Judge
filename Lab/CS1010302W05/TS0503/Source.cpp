// Name: ��౱�(Yu-chen Kuo)
// Date: March, 17, 2022
// Last Update: March, 18, 2022
// Problem statement: �i�H�O���ǥ͸��

#include <iostream>
#include <vector>
using namespace std;

//�w�qstruct
typedef struct {
	string firstName;
	string lastName;
	string phone;
} StRec;

//overloading�A������StRec�O�_�ۦP
bool operator==(StRec a, StRec b) {
	if (a.firstName == b.firstName && a.lastName == b.lastName && a.phone == b.phone) return true;
	else return false;
}

//�ˬd�q�ܸ��X�O�_�X�k
bool checkPhone(string phone) {
	int len = phone.length();
	for (int i = 0; i < len; i++) {
		if (!isdigit(phone[i])) return false; //�t���D�Ʀr�r��
	}
	if (phone[0] != '0') {
		if ((phone[0] == '8' && phone[1] == '8' && phone[2] == '6')) return true; //886�}�Y -> �X�k
	}
	else if (phone[0] != '0' || phone[1] == '0' || phone[1] == '1') return false; //00�}�Y -> ���X�k
	return true;
}

//�ˬd�O�_����
bool checkRepeat(vector<StRec> record, StRec input) {
	vector<StRec>::iterator i;
	for (i = record.begin(); i < record.end(); i++) {
		if (input == *i) return true;
	}
	return false;
}

//�ˬd���׬O�_�X�k
bool checkLength(StRec tmp) {
	if (tmp.firstName.length() >= 25 || tmp.lastName.length() >= 30 || tmp.phone.length() >= 15) {
		return true;
	}
	return false;
}

//������ƿ�J
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
			//�S�����
			if (record.empty()) cout << "Print Error\n";
			else {
				for (i = record.begin(); i != record.end(); i++) {
					cout << i->firstName << " " << i->lastName << " " << i->phone << endl;
				}
			}
		}
		else if (command == "insert") { //command = insert
			getData(&tmp);
			//�����ˬd
			if (checkLength(tmp)) {
				cout << "Input Error\n";
			}
			//��Ƽƶq
			else if (record.size() >= 10) {
				cout << "Insert Error\n";
			}
			//�����ˬd
			else if (checkRepeat(record, tmp)) {
				cout << "Insert Error\n";
			}			
			//�q�ܿ��~
			else if (!checkPhone(tmp.phone)) {
				cout << "Insert Error\n";
			}
			else {
				record.push_back(tmp);
			}
		}
		else if (command == "search") { //command = search
			int index = 0;
			bool flag = true; //�����O�_�����
			getData(&tmp);
			//�����ˬd
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
				//�䤣����
				if (flag) cout << "Search Error\n";
			}
		}
		else if (command == "delete") { //command = delete
			bool flag = true; //�����O�_�����
			getData(&tmp);
			//�����ˬd
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
				//�䤣����
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