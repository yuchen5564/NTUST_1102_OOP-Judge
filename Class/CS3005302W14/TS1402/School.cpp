#include "School.h"

//constructors
School::School(string _name, int _amount)
{
	name = _name;
	studentAmount = _amount;
	studentAmountNextYear = _amount;
}

//增加學生
void School::admissions(int amount)
{
	if (amount > 0) studentAmount += amount; //過濾輸入小於0
}

//減少學生
void School::dropouts(int amount)
{
	if (studentAmount >= amount && amount > 0) studentAmount -= amount; //過濾輸入小於0 && 輸入大於目前總數
}

//轉學
void School::transfer(int amount, School& toSchool)
{
	dropouts(amount); //目前校減少
	toSchool.admissions(amount); //目標校增加
}

//formate output
ostream& operator<<(ostream& output, const School& s)
{
	output << s.name << "\t" << s.studentAmount << "\t" << s.studentAmountNextYear;
	return output;
}

//constructors
PrivateSchool::PrivateSchool(string _name, int _amount)
{
	name = _name;
	studentAmount = _amount;
	studentAmountNextYear = _amount;
	dropoutsCounter = 0;
}

//重載減少學生
void PrivateSchool::dropouts(int amount)
{
	if (studentAmount >= amount && amount > 0) {	//過濾輸入小於0 && 輸入大於目前總數
		if (dropoutsCounter == 0) dropoutsCounter = 1; //超過一次的減少學生-->調降明年名額
		else studentAmountNextYear -= 100;
		studentAmount -= amount;
	}
}

//constructors
PublicSchool::PublicSchool(string _name, int _amount)
{
	name = _name;
	studentAmount = _amount;
	studentAmountNextYear = _amount;
	growth_rate = 0.05;
}

//同意增加招收
void PublicSchool::apply_growth()
{
	studentAmountNextYear += growth_rate * studentAmountNextYear;
}

//重載減少學生
void PublicSchool::dropouts(int amount)
{
	if (studentAmount >= amount && amount > 0) { //過濾輸入小於0 && 輸入大於目前總數
		if (amount > 100) studentAmountNextYear = studentAmountNextYear * 0.95; //一次減少超過100人-->調降明年招收學生
		studentAmount -= amount;
	}
}
