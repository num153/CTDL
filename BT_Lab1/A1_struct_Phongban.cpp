#include <iostream>
#include <string>
using namespace std;

struct Phongban {
	string maPhongban;
	string tenPhongban;
};

void nhap(Phongban &pb) {
	cout << "Nhap ma phong ban: ";
	getline(cin, pb.maPhongban);
	cout << "Nhap ten phong ban: ";
	getline(cin, pb.tenPhongban);
}
void xuat(Phongban pb) {
	cout << "Ma phong ban: " << pb.maPhongban << endl;
	cout << "Ten phong ban: " << pb.tenPhongban << endl;
}

int main() {
	Phongban a;
	nhap(a);
	xuat(a);
	system("pause");
	return 0;
}
