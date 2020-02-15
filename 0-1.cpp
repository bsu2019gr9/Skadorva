/*вычисление значений функции (вариант 10)
f(x)=ln((1+x)/(1-x))+cos2x
eps=0.0001
a=-0.9,b=0.9;
h=0.1
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

double Ln10(double, double);
double Cos10(double, double);
int main() {
	setlocale(LC_ALL, "Russian");
	double a = -0.9, b = 0.9, h = 0.1, eps = 0.0001;
	cout << "\n function value table \n\n";
	for (double x = a; x <= b + (h / 2); x += h) {
		cout << " x = ";
		cout.width(6);
		cout << x;
		cout.width(10);
		cout << Ln10(x, eps) + Cos10(2 * x, eps);
		cout.width(10);
		cout << log10((1 + x) / (1 - x)) + cos(2 * x) << endl;
	}
	system("pause");
	return 0;
}
double Ln10(double x, double eps) {
	double Sum = x, Term = x;
	for (int i = 2; fabs(Term) > eps;) {
		Term *= x * x / ((i+1.0)/(i-1.0));
		Sum += Term;
		i += 2;
	}
	return 2.0 * Sum;
}
double Cos10(double x, double eps) {
	double Sum = 1, Term = 1;
	for (int i = 1; fabs(Term) > eps;) {
		Term *= -x * x / (i * (i + 1.0));
		Sum += Term;
		i += 2;
	}
	return Sum;
}





