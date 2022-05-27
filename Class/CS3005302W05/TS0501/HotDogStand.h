#pragma once
#include <string>
using namespace std;
class HotDogStand {
public:
	HotDogStand(string); //以ID初始化
	HotDogStand(string, int); //以ID&數量初始化
	void justSold(); //售出
	void print(); //輸出品牌與其銷售量
	int thisStandSoldAmount(); //回傳銷售量
	static int allStandSoldAmount(); //回傳總銷售量
private:
	string standId;
	int hotDogSellAmount; 
	static int totalSellAmount; //紀錄總銷售量


};