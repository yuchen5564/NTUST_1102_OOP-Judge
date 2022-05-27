// Name: ��౱�(Yu-chen Kuo)
// Date: March, 10, 2022
// Last Update: March, 10, 2022
// Problem statement: ���gclass�A�Ϩ�i�H�i��Ȧ�b���U�˾ާ@

#include "BankAccount.h"
#include <iostream>
using namespace std;

//�Ȧ��`���B(����)��l��
int BankAccount::total = 0;

//�إ߱b��(�L��l���B)
BankAccount::BankAccount(){
	balance = 0;
}

//�إ߱b��(����l���B)
BankAccount::BankAccount(int input) {
	balance = input;
	total += input;
}

//���X�{��
void BankAccount::withdraw(int input) {
	balance -= input;
	total -= input;
}

//�s�J�{��
void BankAccount::save(int input) {
	balance += input;
	total += input;
}

//���o�b���s��
int BankAccount::getBalance() {
	return balance;
}

//���o�Ȧ椺�`���B
int BankAccount::getAllMoneyInBank() {
	return total;
}