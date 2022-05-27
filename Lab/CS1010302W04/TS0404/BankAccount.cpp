// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 10, 2022
// Last Update: March, 10, 2022
// Problem statement: 撰寫class，使其可以進行銀行帳號各樣操作

#include "BankAccount.h"
#include <iostream>
using namespace std;

//銀行總金額(全域)初始化
int BankAccount::total = 0;

//建立帳號(無初始金額)
BankAccount::BankAccount(){
	balance = 0;
}

//建立帳號(有初始金額)
BankAccount::BankAccount(int input) {
	balance = input;
	total += input;
}

//取出現金
void BankAccount::withdraw(int input) {
	balance -= input;
	total -= input;
}

//存入現金
void BankAccount::save(int input) {
	balance += input;
	total += input;
}

//取得帳號存款
int BankAccount::getBalance() {
	return balance;
}

//取得銀行內總金額
int BankAccount::getAllMoneyInBank() {
	return total;
}