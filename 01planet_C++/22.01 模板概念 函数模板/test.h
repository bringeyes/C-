#pragma once
#include <iostream>
using namespace std;

template<typename T>
T getMax(T* arr, int n) {
	T max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

template<typename T>
T getMin(T* arr, int n) {
	T min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

template<typename T>
double getMean(T* arr, int n) {
	T sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return (double)sum / n;
}

void test04();