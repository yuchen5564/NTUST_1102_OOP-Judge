#pragma once
#include <iostream>
#include <vector>
class NumberGame{
public:
	void SetInput(int);
	void ProcessInput();
	void SetFileName(std::string);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();

private:
	std::string fileName;
	int input;
	std::vector<int> valid; //儲存可被組合出的數值
	std::vector<int> result; //儲存合法數值
};

