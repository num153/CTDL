#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

void nhapChuoi(char* s,int n) {
	cout << "Nhap chuoi (toi da " << n << " ki tu): ";
	cin.getline(s, n + 1);
}

void ghiFile(char* s, int n) {
	ofstream outFile;
	outFile.open("BT4.txt");
	if (outFile.is_open()) {
		for (int i = 0;s[i] != '\0';i++) {
			s[i] = toupper(s[i]);
		}
		outFile << s;
		outFile.close();
	}
	else
	{
		cout << "Khong mo duoc file";
	}
}

int main() {
	const int n = 20;
	char s1[n+1];
	nhapChuoi(s1, n);
	ghiFile(s1, n);
	system("pause");
	return 0;
}
