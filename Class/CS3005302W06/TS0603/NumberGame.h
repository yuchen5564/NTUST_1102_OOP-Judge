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
	std::vector<int> valid; //�x�s�i�Q�զX�X���ƭ�
	std::vector<int> result; //�x�s�X�k�ƭ�
};

