#pragma once
#include <iostream>
#include <vector>
using namespace std;

typedef struct BodyPart{
	string name;
	int amount = 0;
}BodyPart;

class Creature {
public:
	Creature() { name = ""; }
	Creature(string input);//Contains a creature named name.
	Creature(string input, Creature base);//A creature that contains the same information as the base of each body part.
	Creature& operator[](string in);
	Creature& operator=(int input);
	Creature& operator+=(int input);
	Creature& operator-=(int input);
	int operator+(int input);
	int operator-(int input);
	void PrintStatus();
	void PrintLog();
private:
	int index = 0;
	string name;
	int startDayIndex;
	vector<BodyPart> body;
};
