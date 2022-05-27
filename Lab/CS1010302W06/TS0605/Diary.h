#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
	string name;
	string content;
}Event;

typedef struct {
	string name;
	vector<Event> eventList;
}dayLog;

class Diary {
public:
	static void NewDay(string input);
	static void NewEvent(string creatureName, string input);
	static vector<dayLog> day;
};

