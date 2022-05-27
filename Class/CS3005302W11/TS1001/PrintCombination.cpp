// Name: 郭鈺晨(Yu-chen Kuo)
// Date: April, 26, 2022
// Last Update: April, 26, 2022
// Problem statement: Use RECURSION to list all combination.

#include "PrintCombination.h"

//輸出所有組合
void PrintCombination(int* arr, int elements, int choice) {
    static int sz = choice; //紀錄選擇數
    static int el = elements; //紀錄元素數量

    for (int i = elements; i >= choice; i--) {

        arr[choice - 1] = i;

        if (choice > 1) { //如果選擇數大於1，再次進行
            PrintCombination(arr, i - 1, choice - 1);
        }
        else {

            //輸出組合
            for (int i = sz-1; i >= 0; i--) {
                cout << el - arr[i] + 1;
                if (i != 0)cout << " ";
            }

            cout << "\n";
        }
    }
}
