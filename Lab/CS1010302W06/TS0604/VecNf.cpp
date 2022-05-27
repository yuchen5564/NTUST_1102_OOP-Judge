// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 24, 2022
// Last Update: March, 24, 2022
// Problem statement:  define a class named VecNf to store a multidimensional vector and implement some simple vector operations.

#include"VecNf.h"

//初始化(無參數)
VecNf::VecNf() {//Construct a one - dimensional zero vector in default.
	this->~VecNf();
	cnt = 1;
	element = new float[1];
	element[0] = 0.0f;
}

//初始化(有參數)
VecNf::VecNf(float* dest, int cnt_in) {
	this->~VecNf();
	cnt = cnt_in;
	element = new float[cnt];
	for (int i = 0; i < cnt; i++) {
		element[i] = dest[i];
	}
}

//初始化(有參數)
VecNf::VecNf(const VecNf& rhs) {
	if (this == &rhs) {
		return;
	}
	this->~VecNf();
	cnt = rhs.cnt;
	element = new float[cnt];
	for (int i = 0; i < cnt; i++) {
		element[i] = rhs.element[i];
	}
}

//解構子
VecNf::~VecNf() {
	delete[] element;
	element = nullptr;
}

//overloading, a+b
VecNf VecNf::operator+(VecNf in) {
	VecNf result;
	if (cnt != in.cnt) {
		cout << "dimensions inconsistent" << endl;
		return result;
	}
	result.cnt = cnt;
	result.element = new float[result.cnt];
	for (int i = 0; i < cnt; i++) {
		result.element[i] = element[i] + in.element[i];
	}
	return result;
}

//overloading, a-b
VecNf VecNf::operator-(VecNf in) {
	VecNf result;
	if (cnt != in.cnt) {
		cout << "dimensions inconsistent" << endl;
		return result;
	}
	result.cnt = cnt;
	result.element = new float[result.cnt];
	for (int i = 0; i < cnt; i++) {
		result.element[i] = element[i] - in.element[i];
	}
	return result;
}

//overloading, a*b
float VecNf::operator*(VecNf in) {
	float sum = 0;
	if (cnt != in.cnt) {
		cout << "dimensions inconsistent" << endl;
		return 0.0f;
	}
	for (int i = 0; i < cnt; i++) {
		sum += element[i] * in.element[i];
	}
	return sum;
}

//overloading, a=b
VecNf& VecNf::operator=(const VecNf& in) {
	cout << "ASSIGNMENT!!!" << endl;
	if (this == &in) {
		return *this;
	}
	this->~VecNf();
	cnt = in.cnt;
	element = new float[cnt] {};
	for (int i = 0; i < cnt; i++) {
		element[i] = in.element[i];
	}
	return *this;
}

//overloading, 取出指定位置元素
float& VecNf::operator[](int index) {
	return element[index];
}

//overloading, a(float)*b
VecNf VecNf::operator*(double a) {
	VecNf result;
	result.cnt = cnt;
	result.element = new float[result.cnt];
	for (int i = 0; i < result.cnt; i++) {
		result.element[i] = a * element[i];
	}
	return result;
}

int VecNf::Size()
{
	return this->cnt;
}

//overloading, a(float)*b
VecNf operator*(double a, VecNf& x) {
	VecNf result;
	result.cnt = x.cnt;
	result.element = new float[result.cnt];
	for (int i = 0; i < result.cnt; i++) {
		result.element[i] = a * x.element[i];
	}
	return result;
}