#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define MAX 21 //bt4 toi da 20 ki tu
void docFile(char* s,const char* file) {
	ifstream inFile;
	inFile.open(file);
	if (inFile.is_open()) {
		inFile.getline(s,MAX);
		inFile.close();
	}
	else
	{
		cout << "Khong mo duoc file\n";
	}
}
int demKitu(char* s) {
	int dem = 0;
	for (int i = 0;s[i] != '\0';i++) {
		dem++;
	}
	return dem;
}

int main() {
	char s1[MAX];
	docFile(s1, "BT4.txt");
	cout << "So ki tu: " << demKitu(s1) << endl;
	system("pause");
	return 0;
}
