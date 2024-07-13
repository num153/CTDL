#include <iostream>
#include<fstream>
using namespace std;

int tong(int a, int b) {
	return a + b;
}
void tinhTong(int& a, int& b) {
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap b: "; cin >> b;
	ofstream outFile;
	outFile.open("b1.txt");
	if (outFile.is_open()) {
		outFile << tong(a, b);
		outFile.close();
	}
	else
	{
		cout << "Khong mo duoc file";
	}
}

int main() {
	int x, y;
	tinhTong(x, y);
	system("pause");
	return 0;
}
