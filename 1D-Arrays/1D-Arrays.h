
#pragma once
typedef  int pToArr;
void mkOFarr(int n, pToArr& p);
void freeMemory(pToArr& p);
void PrintArray(int* b, int* e);
void inputArray(int* b, int* e);
void initRandomArray(int* b, int* e, const int m = -10, const int M = 10);
void initSortRandArr(int* b, int* e, const int m = -10, const int M = 10);
int findMax(int* b, int* e);
int findMin(int* b, int* e);
int findSum(int* b, int* e);
void reverse(int* b, int* e);
void BubbleSort(int* b, int* e);
void shuffleArr(int*, const int&)