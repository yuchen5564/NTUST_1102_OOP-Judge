// Name: 郭鈺晨(Yu-chen Kuo)
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

	//對切
	while ((first <= last) && !found)
	{
		mid = (first + last) / 2;

		if (key == a[mid]) //找到
		{
			found = true;
			location = mid;
		}
		else if (a[mid] > key) //目前數大於key
		{
			last = mid - 1;
		}
		else if (key > a[mid])  //目前數小於key
		{
			first = mid + 1;
		}
	}
	
}

template<class T>
inline void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	int mid;
	if (first > last) //未找到
	{
		found = false;
	}
	else
	{
		mid = (first + last) / 2;
		if (key == a[mid])     //找到
		{
			found = true;
			location = mid;
		}
		else if (a[mid] > key) // 目前數大於key
		{
			RecBinarySearch(a, first, mid - 1, key, found, location);
		}
		else if (key > a[mid])   //目前數小於key
		{
			RecBinarySearch(a, mid + 1, last, key, found, location);
		}
	}
}
