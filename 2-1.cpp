#include <iostream>
#include <iomanip>
using namespace std;
/* --->FindRowAndReplace<---- ( ) В массиве А(N,М) найти номер строки, среднее арифметическое положительных элементов 
которой является 
наименьшим и поменять её с первой строкой.*/
int**& mkArrOfInt(int , int);
void intRandomArray(int**, int, int, const int , const int);
void intArray(int**, int, int, const int);
void PrintArray(int**, int, int);
void FindRowAndReplace(int**, int, int);
int main() {
	int N =5;
	int M = 5;
	int** dest = mkArrOfInt(N, M);
	intRandomArray(dest, N, M,-10,10);
	PrintArray(dest, N, M);
	FindRowAndReplace(dest, N, M);
	PrintArray(dest, N, M);
}
int**& mkArrOfInt(int N, int M) {
	int** p = new (nothrow) int* [N];
	if (!p) exit(404);
	for (size_t i = 0; i < N; i++) {
		p[i] = new (nothrow) int[M];
		if (!p[i]) exit(404);
	}
	return p;
};
void FreeMemory(int**& p, int N) {
	for (size_t i = 0; i < N; i++) {
		delete[] p[i];
		delete[] p;
		p = nullptr;
	}
}
void intRandomArray(int** p, int N, int M, const int m = -10, const int Max = 10) {
	int d(Max - m + 1);
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++) p[i][j] = rand() % d + m;
}
void intArray(int** p, int N, int M, const int m = 0) {
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++) p[i][j] = m;
}
void PrintArray(int** p, int N, int M) {

	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) cout << setw(3) << p[i][j] << ";";
		cout << '\n';
	}
}
void FindRowAndReplace (int** p, int N, int M) {
	double sum = 0;
	double min(1000);
	int plus(0);
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			if (p[i][j] > 0) {
			  sum += p[i][j];
			  ++plus;
			}
		}
		if ((sum / plus) <= min) min = (sum / plus); 
		plus = 0;
		sum = 0;
	}
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			if (p[i][j] > 0) {
				sum += p[i][j];
				++plus;
			}
		}
		if (min == (sum/plus)) {
			for (size_t j = 0; j < M; j++) {
				int tmp = p[i][j];
				p[i][j] = p[0][j];
				p[0][j] = tmp;
				
			}
			
		}
		sum = 0;
		plus = 0;
	}
}

