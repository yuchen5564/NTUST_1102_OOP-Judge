// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 15, 2022
// Last Update: March, 15, 2022
// Problem statement: 撰寫Class，紀錄熱狗品牌銷售量與全部銷售量

#include "HotDogStand.h"
#include <iostream>
using namespace std;

//總銷售量初始設定
int HotDogStand::totalSellAmount = 0;

//以ID初始化熱狗品牌
HotDogStand::HotDogStand(string id) {
	standId = id;
	hotDogSellAmount = 0;
}

//以ID&數量初始化熱狗品牌
HotDogStand::HotDogStand(string id, int amount) {
	standId = id;
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}

//售出熱狗
void HotDogStand::justSold() {
	hotDogSellAmount++;
	totalSellAmount++;
}

//輸出品牌與其銷售量
void HotDogStand::print() {
	cout << standId << " " << hotDogSellAmount << endl;
}

//回傳銷售量
int HotDogStand::thisStandSoldAmount() {
	return hotDogSellAmount;
}

//回傳總銷售量
int HotDogStand::allStandSoldAmount() {
	return totalSellAmount;
}