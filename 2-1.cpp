/* --->FindRowAndReplace<---- ( ) В массиве А(N,М) найти номер строки, среднее арифметическое положительных элементов
которой является
наименьшим и поменять её с первой строкой.*/
#include <iostream>
#include <iomanip>
using namespace std;
int**& mkArrOfInt(int, int);
void intRandomArray(int**, int, int, const int, const int);
void intArray(int**, int, int, const int);
void PrintArray(int**, int, int);
int* FindRow(int**, int, int);
void FreeMemory(int**&, int);
int main() {
	int N = 5;
	int M = 5;
	int** dest = mkArrOfInt(N, M);
	intRandomArray(dest, N, M, -10, 1);
	PrintArray(dest, N, M);
	int* rowN = FindRow(dest, N, M);
	swap(dest[0], dest[*rowN]);
	PrintArray(dest, N, M);
	FreeMemory(dest, N);

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

	}
	delete[] p;
	p = nullptr;
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
	cout << '\n';
}
int* FindRow(int** p, int N, int M) {
	int* row = nullptr;
	double sum = 0;
	double min(1000);//remix below
	int cnt(0);//cnt
	for (size_t i = 0; i < N; i++) {
		cout << setw(8) << i << p << p[i];
		for (size_t j = 0; j < M; j++) {
			if (p[i][j] > 0) {
				sum += p[i][j];
				++cnt;
			}
		}
		if ((sum / cnt) <= min) {
			min = (sum / cnt); row = p[i];
		}
		cnt = 0;
		sum = 0;
	}
	return row;
}


