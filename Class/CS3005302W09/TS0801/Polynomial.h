#pragma once
#include <iostream>
#include <cmath>
	
class Polynomial
{
public:
	
	Polynomial();
	~Polynomial();
	Polynomial(double* param, int size);

	//for Polynomial a = b;
	Polynomial(const Polynomial& in); //copy same type!!!

	int mySize();
	friend double evaluate(const Polynomial& poly, const double& var);

	Polynomial& operator=(const Polynomial& in);
	double& operator[](int index);

	//overloading for poly = poly1 (+-*) poly2
	Polynomial operator+(Polynomial in);
	Polynomial operator-(Polynomial in);
	Polynomial operator*(Polynomial in);

	//overloading for poly = poly1 (+-*) number
	Polynomial operator+(double in);
	Polynomial operator-(double in);
	Polynomial operator*(double in);
	
	//overloading for poly = number (+-*) poly1
	friend Polynomial operator+(double num, Polynomial in);
	friend Polynomial operator-(double num, Polynomial in);
	friend Polynomial operator*(double num, Polynomial in);
private:
	double* poly = nullptr;
	int size;
};

