#pragma once
#include<iostream>

using namespace std;
class VecNf {
public:
	VecNf();
	VecNf(float* dest, int cnt);
	VecNf(const VecNf& rhs);
	~VecNf();
	VecNf operator+(VecNf);
	VecNf operator-(VecNf);
	float operator*(VecNf);
	VecNf& operator=(const VecNf&);
	float& operator[](int);
	VecNf operator*(double);
	friend VecNf operator*(double, VecNf&);
	int Size();
private:
	float* element = nullptr;
	int cnt = 1;
};