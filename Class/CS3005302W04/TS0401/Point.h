#pragma once
class Point {
public:
	void Set(int, int);	//�]�w�I��
	void Move(int, int); //�����I
	void Rotate(); //����90��
	int RetrieveVertical(); //��Xx�y��
	int RetrieveHorizontal(); //��Xy�y��
private:
	int x = 0;
	int y = 0;
};
