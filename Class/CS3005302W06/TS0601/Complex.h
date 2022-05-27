#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Complex {
public:
	Complex();
	Complex(double);
	Complex(double, double);
	double real();
	double imag();
	friend double real(Complex);
	friend double imag(Complex);
	friend double norm(Complex);

	//overloading
	friend bool operator==(Complex, Complex);
	friend Complex operator+(double, Complex);
	friend Complex operator-(double, Complex);
	friend Complex operator*(double, Complex);
	friend Complex operator/(double, Complex);
	friend Complex operator+(Complex, Complex);
	friend Complex operator-(Complex, Complex);
	friend Complex operator*(Complex, Complex);
	friend Complex operator/(Complex, Complex);
	friend istream& operator>>(istream &input, Complex&);
	friend ostream& operator<<(ostream &output,const Complex& a);

//private:
	double realValue=0, imaginaryValue=0;
};
