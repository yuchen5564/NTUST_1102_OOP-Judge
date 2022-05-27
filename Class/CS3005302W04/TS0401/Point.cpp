// Name: ��౱�(Yu-chen Kuo)
// Date: March, 8, 2022
// Last Update: March, 8, 2022
// Problem statement: ���gclass�A�ާ@�����W�@�I�A�Ϩ�i�H����B����

#include "Point.h"
#include <iostream>
using namespace std;

//�]�w�I��
void Point::Set(int a, int b) {
	x = a;
	y = b;
}

//�����I
void Point::Move(int a, int b) {
	x += a;
	y += b;
}

//����90��
void Point::Rotate() {
	swap(x, y);
	y = y * (-1);
}

//��Xy�y��
int Point::RetrieveHorizontal() {
	return y;
}

//��Xx�y��
int Point::RetrieveVertical() {
	return x;
}