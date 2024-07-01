#include <iostream>
#include<fstream>
using namespace std;

double tbCong(int a, int b, int c) {
	return (double)(a + b + c) / 3;
}
void ghiFile(int& a, int& b, int &c) {
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap b: "; cin >> b;
	cout << "Nhap c: "; cin >> c;
	ofstream outFile;
	outFile.open("BT3.txt");
	if (outFile.is_open()) {
		outFile << a << "#";
		outFile << b << "#";
		outFile << c;
		outFile.close();
	}
	else
	{
		cout << "Khong mo duoc file";
	}
}
void docFile(int a, int b, int c) {
	ifstream inFile;
	inFile.open("BT3.txt");
	if (inFile.is_open()) {
		inFile >> a;
		inFile.ignore();
		inFile >> b;
		inFile.ignore();
		inFile >> c;
		inFile.close();
	}
	else
	{
		cout << "Khong mo duoc file";
	}
}

int main() {
	int x, y,z;
	ghiFile(x, y, z);
	docFile(x, y, z);
	cout << "TB cong: " << tbCong(x, y, z) << endl;
	system("pause");
	return 0;
}
