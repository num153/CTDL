#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAX 50
struct Date {
	int ngay, thang, nam;
};
struct Sach {
	char ten[21];
	char tacgia[21];
	Date nxb;
};
struct Ds {
	int n;
	Sach arr[MAX];
};

void nhap1Sach(Sach &sach) {
	cout << "\nNhap ten sach: ";
	cin>>sach.ten;
	cin.ignore();
	cout << "Nhap ten tac gia: ";
	cin >> sach.tacgia;
	cout << "Ngay xuat ban: "; cin >> sach.nxb.ngay;
	cout << "Thang xuat ban: "; cin >> sach.nxb.thang;
	cout << "Nam xuat ban: "; cin >> sach.nxb.nam;
}
void xuat1Sach(Sach &sach) {
	cout << "Ten sach: " << sach.ten << endl;
	cout << "Tac gia: " << sach.tacgia << endl;
	cout << "Ngay xuat ban: " << sach.nxb.ngay << "/" << sach.nxb.thang << "/" << sach.nxb.nam << endl;
}
void nhapDSsach(Ds &sl) {
	cout << "Nhap so luong sach: "; cin >> sl.n;
	cin.ignore();
	while (sl.n <= 0 || sl.n > 50) {
		cout << "Nhap lai di em: ";
		cin >> sl.n;
		cin.ignore();
	}
	for (int i = 0; i < sl.n; i++) {
		nhap1Sach(sl.arr[i]);
	}
}
void xuatDSsach(Ds sl) {
	for (int i = 0; i < sl.n; i++) {
		cout << "\n====Sach thu " << i + 1 << "====\n";
		xuat1Sach(sl.arr[i]);
	}
}

int main() {
	Ds sach;
	nhapDSsach(sach);
	xuatDSsach(sach);
	system("pause");
	return 0;
}

//Định nghĩa kiểu dữ liệu Sach gồm các thông tin sau :
//-Tên sách kiểu mảng 1 chiều char, tối đa 20 ký tự.
//- Tên tác giả kiểu mảng 1 chiều char, tối đa 20 ký tự.
//- Ngày tháng năm xuất bản kiểu struct NTN(ngày, tháng, năm đều là số
//	nguyên)
//	Viết các hàm sau :
//-Nhập vào thông tin của tối đa 50 quyển sách.
//- Xuất lại thông tin của quyển sách nào có tên tác giả là “Tran Dung”
