// Name: ��౱�(Yu-chen Kuo)
// Date: April, 7, 2022
// Last Update: April, 7, 2022
// Problem statement: can store and calculate polynomial

#include "Polynomial.h"

//�Ѻc���A�R���O����
Polynomial::~Polynomial() {
	delete[] poly;
	poly = nullptr;
	size = 0;
}

//�غc��(�L�ѼƶǤJ)
Polynomial::Polynomial() {
	this->~Polynomial();
	this->size = 1;
	poly = new double[size];
}

//�غc��(�ǤJarray�M�ƶq)
Polynomial::Polynomial(double* param, int size) {
	this->~Polynomial();
	this->size = size;
	this->poly = new double[size] { 0 };
	for (int i = 0; i < size; i++) {
		this->poly[i] = param[i];
	}
	
	//�˴��}�Y�O�_��0
	int count = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (poly[i] != 0) break;
		count++;
	}
	this->size -= count;
}

//�غc��(�ǤJ�t�@��class)
Polynomial::Polynomial(const Polynomial& in) {
	this->~Polynomial();
	this->size = in.size;
	this->poly = new double[size] { };
	for (int i = 0; i < size; i++) {
		this->poly[i] = in.poly[i];
	}
}

//���o�h��������
int Polynomial::mySize() {
	return this->size;
}

//�p��h����
double evaluate(const Polynomial& poly, const double& var) {
	double result = 0;
	for (int i = 0; i < poly.size ; i++) {
		result += (poly.poly[i] * pow(var, i));
	}
	return result;
}

//poly = poly1
Polynomial& Polynomial::operator=(const Polynomial& in) {
	this->~Polynomial();
	this->size = in.size;
	this->poly = new double[size];
	for (int i = 0; i < in.size; i++) {
		this->poly[i] = in.poly[i];
	}
	return *this;
}

// 1.�^�ǫ��w��m�ƭ�
// 2.���w�s�ƭ�
double& Polynomial::operator[](int index) { 
	if (index >= size) {
		Polynomial tmp;
		tmp.size = index + 1;
		tmp.poly = new double[tmp.size]{};
		for (int i = 0; i < this->size; i++) {
			tmp.poly[i] = this->poly[i];
		}
		this->~Polynomial();
		*this = tmp;
		return this->poly[index];
	}
	else return this->poly[index];
}

//==========overloading for poly = poly1 (+-*) poly2==========

//poly = ploy1 + poly2
Polynomial Polynomial::operator+(Polynomial in) {
	Polynomial result;
	int maxSize = 0;
	if (this->size >= in.size) {
		maxSize = this->size;
		result.size = maxSize;
	}
	else {
		maxSize = in.size;
		result.size = maxSize;
	}

	result.poly = new double[maxSize] {};
	for (int i = 0; i < this->size; i++) {
		result.poly[i] += this->poly[i];
	}
	for (int i = 0; i < in.size; i++) {
		result.poly[i] += in.poly[i];
	}
	
	return result;
}

//poly = ploy1 - poly2
Polynomial Polynomial::operator-(Polynomial in) {
	Polynomial result;
	if (this->size >= in.size) {
		result.size = this->size;
	}
	else {
		result.size = in.size;
	}

	result.poly = new double[result.size] {};
	for (int i = 0; i < this->size; i++) {
		result.poly[i] += this->poly[i];
	}
	for (int i = 0; i < in.size; i++) {
		result.poly[i] -= in.poly[i];
	}

	//�˴��}�Y�O�_��0
	int count = 0;
	for (int i = result.size - 1; i >= 0; i--) {
		if (result.poly[i] != 0) break;
		count++;
	}
	result.size -= count;
	return result;
}

//poly = ploy1 * poly2
Polynomial Polynomial::operator*(Polynomial in) {
	Polynomial result;
	result.size = this->size + in.size - 1;
	result.poly = new double[result.size] {};
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < in.size; j++) {
			result.poly[i + j] += this->poly[i] * in.poly[j];
		}
	}

	//�˴��}�Y�O�_��0
	int count = 0;
	for (int i = result.size - 1; i >= 0; i--) {
		if (result.poly[i] != 0) break;
		count++;
	}
	result.size -= count;
	return result;
}

//==========overloading for poly = poly1 (+-*) number==========

//poly = ploy1 + number
Polynomial Polynomial::operator+(double in) {
	Polynomial result;
	result.size = this->size;
	result.poly = new double[result.size]{};
	for (int i = 0; i < this->size; i++) {
		result.poly[i] = this->poly[i];
	}
	result.poly[0] += in;
	return result;
}

//poly = ploy1 - number
Polynomial Polynomial::operator-(double in) {
	Polynomial result;
	result.size = this->size;
	result.poly = new double[result.size]{};
	for (int i = 0; i < this->size; i++) {
		result.poly[i] = this->poly[i];
	}
	result.poly[0] -= in;
	return result;
}

//poly = ploy1 * number
Polynomial Polynomial::operator*(double in) {
	Polynomial result;
	result.size = this->size;
	result.poly = new double[result.size]{};
	for (int i = 0; i < this->size; i++) {
		result.poly[i] = this->poly[i] * in;
	}

	//�˴��}�Y�O�_��0
	int count = 0;
	for (int i = result.size - 1; i >= 0; i--) {
		if (result.poly[i] != 0) break;
		count++;
	}
	result.size -= count;
	return result;
}

//==========overloading for poly = number (+-*) poly1==========

//poly = number + poly1
Polynomial operator+(double num, Polynomial in) {
	Polynomial result;
	result.size = in.size;
	result.poly = new double[result.size]{};
	for (int i = 0; i < in.size; i++) {
		result.poly[i] = in.poly[i];
	}
	result.poly[0] += num;
	return result;
}

//poly = number - poly1
Polynomial operator-(double num, Polynomial in) {
	Polynomial result;
	result.size = in.size;
	result.poly = new double[result.size]{};
	for (int i = 0; i < in.size; i++) {
		result.poly[i] = (-1) * in.poly[i];
	}
	result.poly[0] += num;
	return result;
}

//poly = number * poly1
Polynomial operator*(double num, Polynomial in) {
	Polynomial result;
	result.size = in.size;
	result.poly = new double[result.size]{};
	for (int i = 0; i < in.size; i++) {
		result.poly[i] = in.poly[i] * num;
	}

	//�˴��}�Y�O�_��0
	int count = 0;
	for (int i = result.size - 1; i >= 0; i--) {
		if (result.poly[i] != 0) break;
		count++;
	}
	result.size -= count;
	return result;
}