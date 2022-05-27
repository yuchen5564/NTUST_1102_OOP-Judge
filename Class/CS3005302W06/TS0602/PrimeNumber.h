#pragma once

class PrimeNumber {
public:
	PrimeNumber();
	PrimeNumber(int);
	int get();

	//overloading
	PrimeNumber operator++(int); //a++
	PrimeNumber operator--(int); //a--
	PrimeNumber& operator++(); //++a
	PrimeNumber& operator--(); //--a
private:
	int value;
};
