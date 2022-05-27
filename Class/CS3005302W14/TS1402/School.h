// Name: 郭鈺晨(Yu-chen Kuo)
// Date: May, 23, 2022
// Last Update: May, 23, 2022
// Problem statement: Inheritance class

#pragma once
#include <iostream>
using namespace std;
class School
{
public:
	School() {};
	School(string _name, int _amount);	//constructors
	void admissions(int amount);		//add student
	virtual void dropouts(int amount);	//sub student
	void transfer(int amount, School& toSchool);	//轉學
	friend ostream& operator<<(ostream& output, const School& s); //格式化輸出
protected:
	string name;
	int studentAmount;
	int studentAmountNextYear;
};

class PrivateSchool : public School{
public:
	PrivateSchool(string _name, int _amount);
	void dropouts(int amount);
private:
	int dropoutsCounter;
};

class PublicSchool : public School {
public:
	PublicSchool(string _name, int _amount);
	void apply_growth();
	void dropouts(int amount);
private:
	float growth_rate;
};
