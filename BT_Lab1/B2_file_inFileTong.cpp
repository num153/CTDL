#include <iostream>
#include<fstream>
using namespace std;

void tinhTong(int& a, int& b) {
	/*Doc file luu bien m*/
	int m = 0;
	ifstream inFile;
	inFile.open("b1.txt");
	if (inFile.is_open()) {
		inFile >> m;
		cout << m;
		inFile.close();
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
