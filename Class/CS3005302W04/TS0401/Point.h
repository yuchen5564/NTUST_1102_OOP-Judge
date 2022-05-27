#pragma once
class Point {
public:
	void Set(int, int);	//設定點位
	void Move(int, int); //移動點
	void Rotate(); //旋轉90度
	int RetrieveVertical(); //輸出x座標
	int RetrieveHorizontal(); //輸出y座標
private:
	int x = 0;
	int y = 0;
};
