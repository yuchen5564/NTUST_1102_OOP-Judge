// Name: ³¢à±±á(Yu-chen Kuo)
// Date: March, 24, 2022
// Last Update: April, 17, 2022
// Problem statement:store Diary log.
#include"Diary.h"

//create new day
void Diary::NewDay(string input) {
	dayLog newDay;
	newDay.name = input;
	day.push_back(newDay);
}

//create new event
void Diary::NewEvent(string creatureName, string input) {
	Event newEvent;
	newEvent.name = creatureName;
	newEvent.content = input;
	day[day.size() - 1].eventList.push_back(newEvent);
}