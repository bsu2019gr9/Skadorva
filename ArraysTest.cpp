#include<iostream>
#include<iomanip>
using namespace std;


void fill(int** dynamic_array, size_t , size_t );



int main() {
    int n;

    const int N = 13;
    const int M = 3;
    int** Mas = new int* [M];
    for (size_t i = 0; i < M; i++)
    {
        Mas[i] = new int[N];
    }
    fill(Mas, M, N);
    printArr(Mas, M, N);

    cin >> n;
    for (size_t i = 0; i < M; i++)
    {
        delete[] Mas[i];
    }
    delete[] Mas;
}

void fill(int** dynamic_array, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            
            cout << "A[" << i << "][" << j << "]=";
            cin >> dynamic_array[i][j];
        }
    }

}

void printArr(int** dynamic_array, const size_t N, const size_t M) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) cout << setw(5) << dynamic_array[i][j];
        cout << '\n';
    }
}
