#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Sinhvien {
	string  mssv;
	string ten;
	string diachi;
	int namSinh;
	double diemToan;
	double diemVan;
	double diemNgoaingu;
};
struct Lop {
	int n;
	Sinhvien arr[MAX];
};

void nhap1SV(Sinhvien &sv) {
	cin.ignore();
	cout << "Nhap MSSV: ";
	getline(cin, sv.mssv);
	cout << "Nhap ten sinh vien: ";
	getline(cin, sv.ten);
	cout << "Nhap dia chi sinh vien: ";
	getline(cin, sv.diachi);
	cout << "Nhap nam sinh: ";
	cin >> sv.namSinh;
	cout << "Nhap diem toan: ";
	cin >> sv.diemToan;
	cout << "Nhap diem van: ";
	cin >> sv.diemVan;
	cout << "Nhap diem ngoai ngu: ";
	cin >> sv.diemNgoaingu;
}
void xuat1SV(Sinhvien sv) {
	cout << "MSSV: " << sv.mssv << endl;
	cout << "Ten: " << sv.ten << endl;
	cout << "Dia chi: " << sv.diachi << endl;
	cout << "Nam sinh: " << sv.namSinh << endl;
	cout << "Diem Toan: " << sv.diemToan << endl;
	cout << "Diem Van: " << sv.diemVan << endl;
	cout << "Diem Ngoai ngu: " << sv.diemNgoaingu << endl;
}

void nhapDS(Lop &ds) {
	cout << "Nhap si so lop: ";
	cin >> ds.n;
	while (ds.n > 45 || ds.n<=0) {
		cout << "Nhap lai si so lop (khong qua 45): ";
		cin >> ds.n;
	}
	for (int i = 0; i < ds.n; i++) {
		cout << "\nNhap thong tin sinh vien thu " << i + 1 << endl;
		nhap1SV(ds.arr[i]);
	}
}

void xuatDS(Lop ds) {
	for (int i = 0; i < ds.n; i++) {
		cout << "\n====Sinh vien thu " << i + 1 <<"===" << endl;
		xuat1SV(ds.arr[i]);
	}
}

void xuatTheoChiso(Lop ds) {
	int x;
	cout << "\nMuon xuat sv thu may: ";
	cin >> x;
	while (x > ds.n || x <= 0) {
		cout << "Nhap lai: ";
		cin >> x;
	}
	for (int i = 0; i < ds.n; i++) {
		if (i + 1 == x) {
		cout << "\n====Sinh vien thu " << i + 1 << "===" << endl;
		xuat1SV(ds.arr[i]);
		}
	}
}

double diemTB(double toan, double van, double anh) {
	return (((toan + van) * 2) + anh) / 5;
}

void xuatDTB(Lop ds) {
	for (int i = 0; i < ds.n; i++) {
		cout << "\n====Sinh vien thu " << i + 1 << "===" << endl;
		cout << "MSSV: " << ds.arr[i].mssv << endl;
		cout << "Ten: " << ds.arr[i].ten << endl;
		cout << "Diem TB: " << diemTB(ds.arr[i].diemToan, ds.arr[i].diemVan, ds.arr[i].diemNgoaingu) << endl;
		}
}

void xuatLoai(Lop ds) {
	double dtb = 0;
	for (int i = 0; i < ds.n; i++) {
		dtb = diemTB(ds.arr[i].diemToan, ds.arr[i].diemVan, ds.arr[i].diemNgoaingu);
		if (dtb >= 8) {
			cout << "Gioi" << endl;
		}
		else if (dtb <= 8 && dtb > 6.5) {
			cout << "Kha" << endl;
		}
		else if(dtb<6.5 && dtb>=5)
		{
			cout << "Trung binh" << endl;
		}
		else
		{
			cout << "Duoi TB" << endl;
		}
	}
}

int main() {
	Lop ds;
	nhapDS(ds);
	xuatDS(ds);
	xuatDTB(ds);
	xuatLoai(ds);
	system("pause");
	return 0;
}
