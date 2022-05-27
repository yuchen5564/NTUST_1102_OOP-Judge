// Name: ��౱�(Yu-chen Kuo)
// Date: April, 26, 2022
// Last Update: April, 26, 2022
// Problem statement: Use RECURSION to list all combination.

#include "PrintCombination.h"

//��X�Ҧ��զX
void PrintCombination(int* arr, int elements, int choice) {
    static int sz = choice; //������ܼ�
    static int el = elements; //���������ƶq

    for (int i = elements; i >= choice; i--) {

        arr[choice - 1] = i;

        if (choice > 1) { //�p�G��ܼƤj��1�A�A���i��
            PrintCombination(arr, i - 1, choice - 1);
        }
        else {

            //��X�զX
            for (int i = sz-1; i >= 0; i--) {
                cout << el - arr[i] + 1;
                if (i != 0)cout << " ";
            }

            cout << "\n";
        }
    }
}
