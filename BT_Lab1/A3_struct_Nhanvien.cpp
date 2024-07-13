#include <iostream>
#include <string>
using namespace std;

struct Nhanvien {
	string maNV;
	string tenNV;
	int namVao;
	int namSinh;
};

void nhap1NV(Nhanvien &nv) {
	cout << "Nhap ma nhan vien: ";
	getline(cin, nv.maNV);
	cout << "Nhap ten nhan vien: ";
	getline(cin, nv.tenNV);
	cout << "Nhap nam sinh cua nhan vien: ";
	cin >> nv.namSinh;
	cout << "Nhap nam vao lam cua nhan vien: ";
	cin >> nv.namVao;
}
int tuoiNV(Nhanvien &nv) {
	return 2024 - nv.namSinh;
}
int thamnienNV(Nhanvien &nv) {
	return 2024 - nv.namVao;
}

void xuat1NV(Nhanvien &nv) {
	cout << "Ma nhan vien: " << nv.maNV << endl;
	cout << "Ten nhan vien: " << nv.tenNV << endl;
	cout << "Nam sinh: " << nv.namSinh << endl;
	cout << "Nam vao lam: " << nv.namVao << endl;
	cout << "-----Tuoi cua NV: " << tuoiNV(nv) << endl;
	cout << "-----Tham nien cua NV: " << thamnienNV(nv) << endl;
}


int main() {
	Nhanvien nv;
	nhap1NV(nv);
	xuat1NV(nv);
	system("pause");
	return 0;
}
