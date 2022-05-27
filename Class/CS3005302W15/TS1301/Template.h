// Name: ��౱�(Yu-chen Kuo)
// Date: May, 24, 2022
// Last Update: May, 24, 2022
// Problem statement: Template

#pragma once

#include <string>
#include <iostream>
using namespace std;

template <class T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location);

template <class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location);

template<class T>
inline void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	int mid;
	found = false;

	//���
	while ((first <= last) && !found)
	{
		mid = (first + last) / 2;

		if (key == a[mid]) //���
		{
			found = true;
			location = mid;
		}
		else if (a[mid] > key) //�ثe�Ƥj��key
		{
			last = mid - 1;
		}
		else if (key > a[mid])  //�ثe�Ƥp��key
		{
			first = mid + 1;
		}
	}
	
}

template<class T>
inline void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	int mid;
	if (first > last) //�����
	{
		found = false;
	}
	else
	{
		mid = (first + last) / 2;
		if (key == a[mid])     //���
		{
			found = true;
			location = mid;
		}
		else if (a[mid] > key) // �ثe�Ƥj��key
		{
			RecBinarySearch(a, first, mid - 1, key, found, location);
		}
		else if (key > a[mid])   //�ثe�Ƥp��key
		{
			RecBinarySearch(a, mid + 1, last, key, found, location);
		}
	}
}
