#pragma once
#include <string>
using namespace std;
class HotDogStand {
public:
	HotDogStand(string); //�HID��l��
	HotDogStand(string, int); //�HID&�ƶq��l��
	void justSold(); //��X
	void print(); //��X�~�P�P��P��q
	int thisStandSoldAmount(); //�^�ǾP��q
	static int allStandSoldAmount(); //�^���`�P��q
private:
	string standId;
	int hotDogSellAmount; 
	static int totalSellAmount; //�����`�P��q


};