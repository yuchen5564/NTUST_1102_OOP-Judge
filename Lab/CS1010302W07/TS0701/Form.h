#pragma once
#include <string>
#include <vector>
using namespace std;

class Form{
public:
	void SetInputWord(string);
	void ProcessInputWord();
	void SetFileName(string);
	void Load_CompareWord();
	void PrintFoundWords();
private:
	string inputWord;
	string fileName;
	vector<string> found;
};

