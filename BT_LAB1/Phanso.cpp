#include <iostream>
#include <string>
using namespace std;

struct Phanso {
	int tu, mau;
};

void nhapPS(Phanso &ps) {
	cout << "Nhap tu so: ";
	cin >> ps.tu;
	cout << "Nhap mau so: ";
	cin >> ps.mau;
	while (ps.mau == 0) {
		cout << "Nhap lai mau so: ";
		cin >> ps.mau;
	}

}

void xuatPS(Phanso ps) {
	cout << ps.tu << "/" << ps.mau << endl;
}

void tong2PS(Phanso ps1,Phanso ps2) {
	Phanso kq;
	kq.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
	kq.mau = ps1.mau*ps2.mau;
	cout << "Tong hai phan so: ";
	xuatPS(kq);
}

void hieu2PS(Phanso ps1, Phanso ps2) {
	Phanso kq;
	kq.tu = ps1.tu*ps2.mau - ps1.mau*ps2.tu;
	kq.mau = ps1.mau*ps2.mau;
	cout << "Hieu hai phan so: ";
	xuatPS(kq);
}

void tich2PS(Phanso ps1, Phanso ps2) {
	Phanso kq;
	kq.tu = ps1.tu*ps2.tu;
	kq.mau = ps2.mau*ps2.mau;
	cout << "Tich hai phan so: ";
	xuatPS(kq);
}

void thuong2PS(Phanso ps1, Phanso ps2) {
	Phanso kq;
	kq.tu = ps1.tu*ps2.mau;
	kq.mau = ps1.mau*ps2.tu;
	cout << "thuong hai phan so: ";
	xuatPS(kq);
}

int main() {
	Phanso ps1, ps2;
	nhapPS(ps1);
	nhapPS(ps2);
	cout << "\nPhan so thu 1: ";
	xuatPS(ps1);
	cout << "Phan so thu 2: ";
	xuatPS(ps2);
	tong2PS(ps1, ps2);
	hieu2PS(ps1, ps2);
	tich2PS(ps1, ps2);
	thuong2PS(ps1, ps2);
	system("pause");
	return 0;
}
