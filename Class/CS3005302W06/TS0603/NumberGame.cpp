// Name: ��౱�(Yu-chen Kuo)
// Date: March, 22, 2022
// Last Update: March, 22, 2022
// Problem statement: �Ʀr�C���A��Xlist���A�i�ѿ�J�Ʀr�զX�㰣����

#include "NumberGame.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
using namespace std;

//�]�w�Ʀr
void NumberGame::SetInput(int a) {
	this->input = a;
}

//�w�B�z�A��X�Ҧ��i�Q�զX�X����(�U�줸�ۭ�)
void NumberGame::ProcessInput() {
	int len = to_string(input).length(); //��J�Ʀr���줸��
	int maxDigit = pow(2.0, (double)len); //�i�զX�X�Ʀr���`��
	
	for (int i = 1; i < maxDigit; i++) {
		int sum = 1;
		bitset<32> digit(i); //�H�G�i��D��X�ݭn�ۭ�����
		for (int j = 0; j < len; j++) {
			if (digit[j] == 1) { //�p�G�Q�襤�A�ۭ�
				sum *= (to_string(input)[j] - '0');
			}
		}
		valid.push_back(sum); //��Jvector��
	}
}

//�]�wlist�ɮצW��
void NumberGame::SetFileName(string a) {
	this->fileName = a;
}

//���Jlist���e
void NumberGame::LoadNumberList() {
	fstream file;
	file.open(this->fileName, ios::in);
	int num;
	vector<int>::iterator i;
	while (file >> num) {
		//�p�G�P�i�Q�զX�X���Ʀr�ۦP�A��Jvector��
		for (i = valid.begin(); i != valid.end(); i++) {
			if (*i == num) { 
				result.push_back(num);
				break;
			}
		}
	}
	file.close();
}

//��X�Ҧ��ŦX���󪺼ƭ�
void NumberGame::PrintAllValid() {
	vector<int>::iterator i;
	for (i = result.begin(); i != result.end(); i++) {
		cout << *i << endl;
	}
}

void NumberGame::Reset() {
	valid.clear();
	result.clear();
}