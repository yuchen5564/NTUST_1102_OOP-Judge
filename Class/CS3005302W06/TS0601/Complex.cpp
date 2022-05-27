// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 22, 2022
// Last Update: March, 22, 2022
// Problem statement: 複數計算

#include "Complex.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

//初始化(無初始值)
Complex::Complex() {
	realValue = 0;
	imaginaryValue = 0;
}

//初始化(初始值只有實數)
Complex::Complex(double a) {
	realValue = a;
	imaginaryValue = 0;
}

//初始化(初始值有實數+虛數)
Complex::Complex(double a, double b) {
	realValue = a;
	imaginaryValue = b;
}

//回傳實數
double Complex::real() {
	return realValue;
}

//回傳虛數
double Complex::imag() {
	return imaginaryValue;
}

//設定實數
double real(Complex a) {
	return a.realValue;
}

//設定虛數
double imag(Complex a) {
	return a.imaginaryValue;
}

//回傳 √(realValue^2  + imaginaryValue^2)
double norm(Complex a) {
	return pow(pow(a.realValue, 2) + pow(a.imaginaryValue, 2), 0.5);
}

//overloading, 比較兩複數是否相等
bool operator==(Complex a, Complex b) {
	if (a.realValue == b.realValue && a.imaginaryValue == b.imaginaryValue) return true;
	else return false;
}

//overloading, 兩複數相加
Complex operator+(Complex a, Complex b) {
	Complex tmp;
	tmp.realValue = a.realValue + b.realValue;
	tmp.imaginaryValue = a.imaginaryValue + b.imaginaryValue;
	return tmp;
}

//overloading, 兩複數相減
Complex operator-(Complex a, Complex b) {
	Complex tmp;
	tmp.realValue = a.realValue - b.realValue;
	tmp.imaginaryValue = a.imaginaryValue - b.imaginaryValue;
	return tmp;
}

//overloading, 兩複數相乘
Complex operator*(Complex a, Complex b) {
	Complex tmp;
	tmp.realValue = a.realValue * b.realValue - a.imaginaryValue * b.imaginaryValue;
	tmp.imaginaryValue = a.imaginaryValue * b.realValue + a.realValue * b.imaginaryValue;
	return tmp;
}

//overloading, 兩複數相除
Complex operator/(Complex a, Complex b) {
	Complex tmp;
	double denominator = pow(b.realValue, 2) + pow(b.imaginaryValue, 2); //分母
	tmp.realValue = (a.realValue * b.realValue + a.imaginaryValue * b.imaginaryValue) / denominator;
	tmp.imaginaryValue = (a.imaginaryValue * b.realValue - a.realValue * b.imaginaryValue) / denominator;
	return tmp;
}

//overloading, 複數+實數
Complex operator+(double n, Complex a) {
	Complex tmp;
	tmp.realValue = n + a.realValue;
	tmp.imaginaryValue = a.imaginaryValue;
	return tmp;
}

//overloading, 複數-實數
Complex operator-(double n, Complex a) {
	Complex tmp;
	tmp.realValue = n - a.realValue;
	tmp.imaginaryValue =(-1)* a.imaginaryValue;
	return tmp;
}

//overloading, 複數*實數
Complex operator*(double n, Complex a) {
	Complex tmp;
	tmp.realValue = n * a.realValue;
	tmp.imaginaryValue = n * a.imaginaryValue;
	return tmp;
}

//overloading, 實數/複數
Complex operator/(double n, Complex a) {
	Complex tmp;
	double denominator = pow(a.realValue, 2) + pow(a.imaginaryValue, 2); //分母
	tmp.realValue = n * a.realValue / denominator;
	tmp.imaginaryValue = n * (-1) * a.imaginaryValue / denominator;
	return tmp;
}

//複數型態輸出
istream& operator>>(istream& input, Complex& a) {
	string tmp;
	int flag = 0;
	getline(input, tmp);
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == '-') break;
		if (!isdigit(tmp[i])) {
			tmp[i] = ' ';
		}
	}
	istringstream in(tmp);
	in >> a.realValue >> a.imaginaryValue;
	
	return input;
}

//複數型態輸入
ostream& operator<<(ostream& output,const Complex& a) {
	output << a.realValue << " + " << a.imaginaryValue << "*i";
	return output;
}
