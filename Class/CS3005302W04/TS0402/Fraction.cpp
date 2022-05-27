// Name: 尝啾贬(Yu-chen Kuo)
// Date: March, 8, 2022
// Last Update: March, 8, 2022
// Problem statement: 级糶class璸衡块计だ计

#include "Fraction.h" 
#include <iostream>
#include <cmath>
using namespace std;

//т程そ计
int gcd(int n, int m) {
	if (m == 0) return n;
	else return gcd(m, n % m);
}

//砞﹚砆埃计
void Fraction::setNumerator(int x) {
	numerator = x;
}

//砞﹚埃计
void Fraction::setDenominator(int x) {
	denominator = x;
}

//块计篈计
void Fraction::getDouble() {
	double tmp = (double)numerator / (double)denominator;
	int tmp2 = tmp;	//既俱计场だ
	if (tmp2 == tmp) printf("%d\n", tmp2); //狦俱计ㄏノ%d块
	else printf("%.6f\n", tmp); //狦Τ计块计翴材6

}

//块だ计篈计
void Fraction::outputReducedFraction() {
	int num = gcd(numerator, denominator); //眔ㄢ计程そ计
	if (denominator / num == 1) cout << numerator / num << endl; //狦だダ=1钡块
	else cout << numerator / num << "/" << denominator / num << endl; //狦だダ!=1Αて块
}