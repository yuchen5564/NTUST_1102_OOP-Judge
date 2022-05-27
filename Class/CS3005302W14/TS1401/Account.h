// Name: ³¢à±±á(Yu-chen Kuo)
// Date: May, 23, 2022
// Last Update: May, 23, 2022
// Problem statement: throwing an exception

#pragma once

//exception for balance < 0
class InsufficientFunds {
public:
	InsufficientFunds() {};
};

//exception for negative deposit
class NegativeDeposit {
public:
	NegativeDeposit() {};
};

class Account
{
private:
	double balance;
public:
	Account() { balance = 0; }
	Account(double initialDeposit) { balance = initialDeposit; }
	double getBalance() { return balance; }

	//returns new balance or -1 if error 
	double deposit(double amount)
	{
		if (amount > 0) balance += amount;
		else throw NegativeDeposit();
		return balance;
	}

	//return new balance or -1 if invalid amount 
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0)) throw InsufficientFunds();
		else balance -= amount;
		return balance;
	}


};

