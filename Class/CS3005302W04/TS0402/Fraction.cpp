// Name: ��౱�(Yu-chen Kuo)
// Date: March, 8, 2022
// Last Update: March, 8, 2022
// Problem statement: ���gclass�A�p��ÿ�X�p�ơB����

#include "Fraction.h" 
#include <iostream>
#include <cmath>
using namespace std;

//��X�̤j���]��
int gcd(int n, int m) {
	if (m == 0) return n;
	else return gcd(m, n % m);
}

//�]�w�Q����
void Fraction::setNumerator(int x) {
	numerator = x;
}

//�]�w����
void Fraction::setDenominator(int x) {
	denominator = x;
}

//��X�p�ƫ��A�Ʀr
void Fraction::getDouble() {
	double tmp = (double)numerator / (double)denominator;
	int tmp2 = tmp;	//�Ȧs��Ƴ���
	if (tmp2 == tmp) printf("%d\n", tmp2); //�p�G���¾�ơA�ϥ�%d��X
	else printf("%.6f\n", tmp); //�p�G���p�Ʀ�A��X�ܤp���I���6��

}

//��X���ƫ��A�Ʀr
void Fraction::outputReducedFraction() {
	int num = gcd(numerator, denominator); //���o��Ƴ̤j���]��
	if (denominator / num == 1) cout << numerator / num << endl; //�p�G����=1�A������X
	else cout << numerator / num << "/" << denominator / num << endl; //�p�G����!=1�A�榡�ƿ�X
}