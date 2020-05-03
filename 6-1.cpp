#include<iostream>
#include<fstream> 
#include<cmath>
using namespace std;
struct color { unsigned char r, g, b; };

int main() {
	ifstream fin("c:\\IT\\3.bmp", ios::binary);
	ofstream fout("c:\\IT\\rez3.bmp", ios::binary);
	if (!fin) { cout << "No file c:\\IT\\3.bmp. Can't open\n"; exit(1); }
	if (!fout) { cout << "   file c:\\IT\\rez3.bmp. Can't create\n"; exit(1); }

	char buf[30];
	color c1, c2;
	unsigned int w, h;
	fin.read((char*)&buf, 18);
	fout.write((char*)&buf, 18);

	fin.read((char*)&w, 4); cout << "w=" << w;  
	fin.read((char*)&h, 4); cout << ", h=" << h;
	
	w = 256;fout.write((char*)&w, 4);
	h = 256;fout.write((char*)&h, 4);
	fin.read((char*)&buf, 28);
	fout.write((char*)&buf, 28);

	cout << "Please, input color1 values:"; cin >> c1.r >> c1.g >> c1.b;
	cout << "Please, input color2 values:"; cin >> c2.r >> c2.g >> c2.b;
	double StepR = 1.0*(abs(c2.r - c1.r))/ (w * h);
	double StepG = 1.0*(abs(c2.g - c1.g))/ (w * h);
	double StepB = 1.0*(abs(c2.b - c1.b))/ (w * h);
	double cR = c1.r, cG = c1.g, cB = c1.b;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			fout.write((char*)&c1, 3);
			cR += StepR; c1.r = cR;
			cB += StepB; c1.b = cB;
			cG += StepG; c1.g = cG;
		}
	}
	fin.close();
	fout.close();
	return 1;
}