#include<iostream>
#include<iomanip>
using namespace std;
typedef int* pToArr;
void mkOFarr(int n, pToArr& p);
void freeMemory(pToArr& p);
void PrintArray(int* b, int* e);
void inputArray(int* b, int* e);
void initRandomArray(int* b, int* e, const int m, const int M);
int Task1(int* b, int* e, const int m, const int M);
void reverse(int* b, int* e);
int main(){
	int n(0);
	cout << "Please,input lenght of array" << "\n";
	cin >> n;
	int* dest = nullptr;
	mkOFarr(n, dest);
	Task1(dest, dest + n,-10,10);
	PrintArray(dest, dest + n);
	freeMemory(dest);

	cin >> n;
}

void PrintArray(int* b, int* e) {
	for (int* p = b; b < e; ++p)
		cout << *p;
};
void reverse(int* b, int* e) {
	for (int* p = b,*q = e - 1; p < q; ++p,--q) {
		swap(*p, *q);
	}
};
void inputArray(int* b, int* e) {
	for (int* p = b; b < e; ++p)
		cin >> *p;
}
void mkOFarr(int n, pToArr& p) {//
	p = new (nothrow) int[n];
	if (!p) exit(404);
};
void freeMemory(pToArr& p) { delete[] p; p = nullptr; };//
void initArray(int* b, int* e, const int m) {
	for (int* p = b; b < e; ++p)
		*p = m;
};
void initRandomArray(int* b, int* e) {
	const int m = -10,  M = 10;
	int d = (M - m + 1);
	for (int* p = b; b < e; ++ p) *p = rand() % d + m;

};
int Task1(int* b, int* e, const int m ,const int M  ) {
	int d = (M - m + 1);
	for (int *p = b; b < e; ++p)	*p = rand() % d + m;
	int inum_of_el(0);
	int how_much(0);
	int tmp= *b;
	for (int* p = b; p < e; ++p)
	{
	
		if (inum_of_el >= 2)++how_much;
		if (tmp != *p) {
			inum_of_el = 0; tmp = *p;
		}
		++inum_of_el;

	}
	return how_much;
};
int Task2(int* b, int* e, const int m, const int M) {
	int d = (M - m + 1);
	for (int* p = b; b < e; ++p)	*p = rand() % d + m;
	int inum_of_el(0);
	int how_much(1);
	int tmp = *b;
	for (int* p = b; p < e; ++p)
	{

		if (tmp = *p) { 
			++how_much;
		}
		else { tmp = *p; }

	}
	return how_much;
};