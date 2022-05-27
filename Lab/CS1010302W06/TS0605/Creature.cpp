// Name: 郭鈺晨(Yu-chen Kuo)
// Date: March, 24, 2022
// Last Update: April, 17, 2022
// Problem statement:store Creature's body part.

#include "Creature.h"
#include "Diary.h"
vector<dayLog> Diary::day;

//排序用
bool compare_string(BodyPart a, BodyPart b) {
	return a.name < b.name;
}

//初始化
Creature::Creature(string input) {
	name = input;
	startDayIndex = Diary::day.size() - 1;
}

//初始化(含有其他物種參數)
Creature::Creature(string input, Creature base) {
	name = input;
	body = base.body;
	startDayIndex = Diary::day.size() - 1;
}

//get body part index
Creature& Creature::operator[](string in) {
	for (unsigned int i = 0; i < body.size(); i++) {
		if (in == body[i].name) {
			index = i;
			return *this;
		}
	}
	//create new part
	index = body.size();
	BodyPart newPart;
	newPart.name = in;
	newPart.amount = 0;
	body.push_back(newPart);
	return *this;
}

//紀錄部位增加量
Creature& Creature::operator=(int input) {
	string output = "'s " + body[index].name;
	//new part
	if (!body[index].amount && input) {
		output = output + " appeared (";
	}
	//part incressed
	else if (input > body[index].amount) {
		output = output + " increased (";
	}
	//part decressed
	else if (input < body[index].amount) {
		output = output + " decreased (";
	}
	else {
		return *this;
	}
	//add to log
	output = output + to_string(body[index].amount) + " -> ";
	body[index].amount = input;
	output = output + to_string(body[index].amount) + ").";
	Diary::NewEvent(name, output);
	return *this;
}

//overloading, add
Creature& Creature::operator+=(int input) {
	return ((*this) = ((*this) + input));
}

//overloading, cut
Creature& Creature::operator-=(int input) {
	return ((*this) = ((*this) - input));
}

//overloading, add
int Creature::operator+(int input) {
	return body[index].amount + input;
}

//overloading, cut
int Creature::operator-(int input) {
	return body[index].amount - input;
}

//print body part status
void Creature::PrintStatus() {
	sort(body.begin(), body.end(), compare_string); //sort
	cout << name << "'s status:" << endl;
	for (int i = 0; i < body.size(); i++) {
		if (body[i].amount != 0) {
			cout << body[i].name << " * " << body[i].amount << endl;
		}
	}
	cout << endl;
}

//print body log
void Creature::PrintLog() {
	cout << name << "'s log:" << endl;
	for (int i = startDayIndex; i < Diary::day.size(); i++) {
		cout << "Day " << Diary::day[i].name << endl;
		for (int j = 0; j < Diary::day[i].eventList.size(); j++) {
			if (Diary::day[i].eventList[j].name == name) {
				cout << name << Diary::day[i].eventList[j].content << endl;
			}
		}
	}
	cout << endl;
}