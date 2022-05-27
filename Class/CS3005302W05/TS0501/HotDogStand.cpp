// Name: ��౱�(Yu-chen Kuo)
// Date: March, 15, 2022
// Last Update: March, 15, 2022
// Problem statement: ���gClass�A���������~�P�P��q�P�����P��q

#include "HotDogStand.h"
#include <iostream>
using namespace std;

//�`�P��q��l�]�w
int HotDogStand::totalSellAmount = 0;

//�HID��l�Ƽ����~�P
HotDogStand::HotDogStand(string id) {
	standId = id;
	hotDogSellAmount = 0;
}

//�HID&�ƶq��l�Ƽ����~�P
HotDogStand::HotDogStand(string id, int amount) {
	standId = id;
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}

//��X����
void HotDogStand::justSold() {
	hotDogSellAmount++;
	totalSellAmount++;
}

//��X�~�P�P��P��q
void HotDogStand::print() {
	cout << standId << " " << hotDogSellAmount << endl;
}

//�^�ǾP��q
int HotDogStand::thisStandSoldAmount() {
	return hotDogSellAmount;
}

//�^���`�P��q
int HotDogStand::allStandSoldAmount() {
	return totalSellAmount;
}