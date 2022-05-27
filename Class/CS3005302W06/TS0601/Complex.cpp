// Name: ��౱�(Yu-chen Kuo)
// Date: March, 22, 2022
// Last Update: March, 22, 2022
// Problem statement: �Ƽƭp��

#include "Complex.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

//��l��(�L��l��)
Complex::Complex() {
	realValue = 0;
	imaginaryValue = 0;
}

//��l��(��l�ȥu�����)
Complex::Complex(double a) {
	realValue = a;
	imaginaryValue = 0;
}

//��l��(��l�Ȧ����+���)
Complex::Complex(double a, double b) {
	realValue = a;
	imaginaryValue = b;
}

//�^�ǹ��
double Complex::real() {
	return realValue;
}

//�^�ǵ��
double Complex::imag() {
	return imaginaryValue;
}

//�]�w���
double real(Complex a) {
	return a.realValue;
}

//�]�w���
double imag(Complex a) {
	return a.imaginaryValue;
}

//�^�� ��(realValue^2  + imaginaryValue^2)
double norm(Complex a) {
	return pow(pow(a.realValue, 2) + pow(a.imaginaryValue, 2), 0.5);
}

//overloading, �����ƼƬO�_�۵�
bool operator==(Complex a, Complex b) {
	if (a.realValue == b.realValue && a.imaginaryValue == b.imaginaryValue) return true;
	else return false;
}

//overloading, ��ƼƬۥ[
Complex operator+(Complex a, Complex b) {
	Complex tmp;
	tmp.realValue = a.realValue + b.realValue;
	tmp.imaginaryValue = a.imaginaryValue + b.imaginaryValue;
	return tmp;
}

//overloading, ��ƼƬ۴�
Complex operator-(Complex a, Complex b) {
	Complex tmp;
	tmp.realValue = a.realValue - b.realValue;
	tmp.imaginaryValue = a.imaginaryValue - b.imaginaryValue;
	return tmp;
}

//overloading, ��ƼƬۭ�
Complex operator*(Complex a, Complex b) {
	Complex tmp;
	tmp.realValue = a.realValue * b.realValue - a.imaginaryValue * b.imaginaryValue;
	tmp.imaginaryValue = a.imaginaryValue * b.realValue + a.realValue * b.imaginaryValue;
	return tmp;
}

//overloading, ��ƼƬ۰�
Complex operator/(Complex a, Complex b) {
	Complex tmp;
	double denominator = pow(b.realValue, 2) + pow(b.imaginaryValue, 2); //����
	tmp.realValue = (a.realValue * b.realValue + a.imaginaryValue * b.imaginaryValue) / denominator;
	tmp.imaginaryValue = (a.imaginaryValue * b.realValue - a.realValue * b.imaginaryValue) / denominator;
	return tmp;
}

//overloading, �Ƽ�+���
Complex operator+(double n, Complex a) {
	Complex tmp;
	tmp.realValue = n + a.realValue;
	tmp.imaginaryValue = a.imaginaryValue;
	return tmp;
}

//overloading, �Ƽ�-���
Complex operator-(double n, Complex a) {
	Complex tmp;
	tmp.realValue = n - a.realValue;
	tmp.imaginaryValue =(-1)* a.imaginaryValue;
	return tmp;
}

//overloading, �Ƽ�*���
Complex operator*(double n, Complex a) {
	Complex tmp;
	tmp.realValue = n * a.realValue;
	tmp.imaginaryValue = n * a.imaginaryValue;
	return tmp;
}

//overloading, ���/�Ƽ�
Complex operator/(double n, Complex a) {
	Complex tmp;
	double denominator = pow(a.realValue, 2) + pow(a.imaginaryValue, 2); //����
	tmp.realValue = n * a.realValue / denominator;
	tmp.imaginaryValue = n * (-1) * a.imaginaryValue / denominator;
	return tmp;
}

//�Ƽƫ��A��X
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

//�Ƽƫ��A��J
ostream& operator<<(ostream& output,const Complex& a) {
	output << a.realValue << " + " << a.imaginaryValue << "*i";
	return output;
}
