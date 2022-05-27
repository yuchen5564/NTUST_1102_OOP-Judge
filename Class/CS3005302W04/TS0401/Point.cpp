// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 8, 2022
// Last Update: March, 8, 2022
// Problem statement: 撰寫class，操作平面上一點，使其可以旋轉、移動

#include "Point.h"
#include <iostream>
using namespace std;

//設定點位
void Point::Set(int a, int b) {
	x = a;
	y = b;
}

//移動點
void Point::Move(int a, int b) {
	x += a;
	y += b;
}

//選轉90度
void Point::Rotate() {
	swap(x, y);
	y = y * (-1);
}

//輸出y座標
int Point::RetrieveHorizontal() {
	return y;
}

//輸出x座標
int Point::RetrieveVertical() {
	return x;
}