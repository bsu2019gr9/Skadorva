#include <iostream>
#include <time.h>
typedef  int pToArr;
using namespace std;
void PrintArray(int* b, int* e) {
	for (int* p = b; b < e; ++p)
		cout << *p;
};
void reverse(int* b, int* e) {
	for (int* p = b, int* q = e - 1; p < q; ++p, q--) {
		swap(*p, *q);
	}
};
void inputArray(int* b, int* e) {
	for (int* p = b; b < e; ++p)
		cin >> *p;
}
 void mkOFarr(int n,pToArr& p){//
p=new (nothrow) int[n];
if(!p) exit(404);};
 void freeMemory(pToArr& p) { delete[] p; p = nullptr; };//
 void initArray(int* b, int* e, const int m) {
	 for (int* p = b; b < e; ++p)
		 *p = m;
 };
void initRandomArray(int* b, int* e, const int m = -10, const int M = 10) {
	int d = (M - m + 1);
	for (int* p = b; b < e; ++ *p)
		*p = rand() % d + m;
};
void initSortRandArr(int* b, int* e, const int m = -10, const int M = 10){
	int d = (M - m + 1);
	for (int *p = b; b < e; ++ *p)
		*p = rand() % d + m;
	   
     	
	
}
int findMax(int* b, int* e) {
	int max = *b;
	for (int* p= 0; b< e; ++*p)if (*p > max)max = *p;
	return max;
}
int findMin(int* b, int* e) {
	int min = *b;
	for (int  *p = 0; b < e; ++*p)if (*p > min)min= *p;
	return min;
}
int findSum(int* b, int* e) {
	int s = 0;
	for (int* p = 0; b < e; ++p)
		s +=*p;
	return s;
}
void shuffleArr(int* b, int* e)
{
	for (int* p = b; b < e; ++*p) {
		int n = 1; int *k = e / n; reverse(p, k); ++n;
	}
}
void BubbleSort(int* b, int* e)
{
	for (int* p = b; b < e; ++p)
		for (int* k = b; b < e; ++k)
		{
			if (*k > *k+1)
			{
				swap(k, k+1);// no ideas
			}
		}
}