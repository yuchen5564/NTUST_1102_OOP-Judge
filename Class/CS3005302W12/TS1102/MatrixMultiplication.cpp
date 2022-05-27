// Name: 郭鈺晨(Yu-chen Kuo)
// Date: May, 03, 2022
// Last Update: May, 03, 2022
// Problem statement: multiplication matrix

#include <iostream>
using namespace std;

//建立二維陣列儲存矩陣元素
void createMatrix(int row, int col, float* matrix[]) {
	for (int i = 0; i < row; i++) {
		matrix[i] = new float[col] {};
	}
}

//取得矩陣內元素
void getMatrix(int row, int col, float* matrix[]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];
		}
	}
}

//刪除二維陣列記憶體
void deleteMatrix(int row, float* matrix[]) {
	for (int i = 0; i < row; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

//輸出矩陣
void printMatrix(int row, int col, float* matrix[]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if(j == col -1)	cout << matrix[i][j];
			else cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//矩陣乘法
float countMatrix(int col, int row, float* matrixA, float* matrixB[]) {
	float sum = 0;
	for (int i = 0; i < col; i++) {
		sum += matrixA[i] *matrixB[i][row];
	}
	return sum;
}

int main() {
	float** matrixA, ** matrixB, ** matrix;
	int rowA, colA, rowB, colB;

	while (cin >> rowA >> colA >> rowB >> colB) {

		//宣告&建立二維陣列
		matrixA = new float* [rowA];
		createMatrix(rowA, colA, matrixA);
		getMatrix(rowA, colA, matrixA);

		matrixB = new float* [rowB];
		createMatrix(rowB, colB, matrixB);
		getMatrix(rowB, colB, matrixB);

		matrix = new float* [rowA];
		createMatrix(rowA, colB, matrix);

		//colA != rowB --> 矩陣無法相乘
		if (colA != rowB) {
			cout << "Matrix multiplication failed.\n";
			break;
		}

		//乘法計算
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colB; j++) { //結果選位
				matrix[i][j] = countMatrix(colA, j, matrixA[i], matrixB);
			}
		}

		//output
		printMatrix(rowA, colB, matrix);

		deleteMatrix(rowA, matrixA);
		deleteMatrix(rowB, matrixB);
		deleteMatrix(rowA, matrix);
	}
	return 0;
}