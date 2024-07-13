#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

struct Date {
	int ngay, thang, nam;
};
struct Lop {
	char malop[5]; //IT23
	char tenlop[9]; //DH23IT02
	string tenkhoa;
	int sosv;
	Date ngaykg;
};
struct DS {
	int n;
	Lop *arr;
};

void del(DS sl) {
	delete[] sl.arr;
	sl.arr = nullptr;
}
bool namNhuan(int _nam) {
	if (_nam % 400 == 0 || (_nam % 4 == 0 && _nam % 100 != 0))
		return true;
	return false;
}
int tinhNgay(int _thang, int _nam) {
	int _ngay = 0;
	switch (_thang) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		_ngay = 31;
		break;
	case 4: case 6: case 9: case 11:
		_ngay = 30;
		break;
	case 2:
		if (namNhuan(_nam)) {
			_ngay = 29;
		}
		else {
			_ngay = 28;
		}
		break;
	}
	return _ngay;
}
bool checkDate(const Date ntn) {
	if (ntn.nam <= 0)
		return false;
	if (ntn.thang < 1 || ntn.thang>12)
		return false;
	if (ntn.ngay <= 0 || ntn.ngay > tinhNgay(ntn.thang, ntn.nam))
		return false;
	return true;
}
//=================Nhap xuat 1 Lop============
void nhap1lop(Lop& l) {
	cout << "Nhap ma lop: ";
	cin >> l.malop;
	cout << "Nhap ten lop: ";
	cin >> l.tenlop;
	cout << "Nhap ten khoa: ";
	cin.ignore();
	getline(cin, l.tenkhoa);
	cout << "Nhap so sv: ";
	cin >> l.sosv;
	Date ntn;
	cout << "Nhap ngay khai giang: ";
	cin >> ntn.ngay;
	cout << "Nhap thang khai giang: ";
	cin >> ntn.thang;
	cout << "Nhap nam khai giang: ";
	cin >> ntn.nam;
	if (checkDate(ntn)) {
		l.ngaykg = ntn;
	}
	else {
		cout << "Ngay k hop le\n";
	}
}
void xuat1lop(Lop l) {
	cout << "Ma lop: " << l.malop << endl;
	cout << "Ten lop: " << l.tenlop << endl;
	cout << "Ten khoa: " << l.tenkhoa << endl;
	cout << "So sv: " << l.sosv << endl;
	cout << "Ngay khai giang: ";
	if (checkDate(l.ngaykg)) {
		cout << l.ngaykg.ngay << "/" << l.ngaykg.thang << "/" << l.ngaykg.nam << endl;
	}
	else
		cout << "Khong hop le\n";
}
//===================Nhap Xuat DS===================
void nhapDSlop(DS & sl) {
	cout << "Nhap so luong lop: ";
	cin >> sl.n;
	cin.ignore();//bo enter
	sl.arr = new Lop[sl.n];
	for (int i = 0;i < sl.n;i++) {
		Lop l;
		cout << "\n======Nhap thong tin cho lop thu " << i + 1 << " ======" << endl;
		nhap1lop(sl.arr[i]);
	}
}
void xuatDSlop(DS sl) {
	for (int i = 0;i < sl.n;i++) {
		cout << "\n=====Lop thu " << i + 1 << "=====\n";
		xuat1lop(sl.arr[i]); 
	}
}

void docFile(DS& sl) {
	ifstream inFile;
	inFile.open("BT4.txt");
	if (inFile.is_open()) {
		inFile >> sl.n;
		inFile.ignore();  //ignore sau khi nhap so luong

		sl.arr = new Lop[sl.n];

		int i = 0;
		while (i < sl.n && !inFile.eof()) {
			Lop l;
			inFile.getline(l.malop, 5, '#');
			inFile.getline(l.tenlop, 9, '#');
			getline(inFile, l.tenkhoa, '#');
			inFile >> l.sosv;
			inFile.ignore();
			inFile >> l.ngaykg.ngay;
			inFile.ignore();
			inFile >> l.ngaykg.thang;
			inFile.ignore();
			inFile >> l.ngaykg.nam;
			inFile.ignore();

			if (checkDate(l.ngaykg)) {
				sl.arr[i] = l;  // gan 1 lop vao mang ds lop
				i++;
			}
			else {
				cout << "Ngay khong hop le\n";
			}
		}
		inFile.close();
	}
	else {
		cout << "Khong the mo file\n";
	}
}
//===================Dem===================
void demSV(DS& sl, const string& khoa) {
	int dem = 0;
	Lop l;
	for (int i = 0;i < sl.n;i++) {
		if (sl.arr[i].tenkhoa == khoa) {
			dem = dem + sl.arr[i].sosv; //chu y khong phai l.sosv vi no se k cap nhat l
		}

	}
	cout << "\nTong sv khoa " << khoa << " la: " << dem << endl;
}
void demLop(DS& sl, const string& khoa) {
	int dem = 0;
	for (int i = 0;i < sl.n;i++) {
		if (sl.arr[i].tenkhoa == khoa) {
			dem++;
		}
	}
	cout << "Tong so lop khoa " << khoa << " la: " << dem << endl;
}
void xoa1lop(DS& sl) {
	int x;
	cout << "\nMuon xoa lop thu may: "; cin >> x;
	if (x < 1 || x > sl.n) {
		cout << "Khong ton tai lop thu " << x << endl;
		return;
	}
	for (int i = x - 1; i < sl.n - 1; ++i) {
		sl.arr[i] = sl.arr[i + 1];
	}
	sl.n--;
}
void xoaLopKhoa(DS& sl, const string& khoa) {
	for (int i = 0;i < sl.n;i++) {
		if (sl.arr[i].tenkhoa == khoa) {
				sl.arr[i] = sl.arr[i + 1];
			sl.n--;
		}
	}
}
int main() {
	DS ds1;
	int chon;
	string s1, s2,s3;
	do {
		cout << "\t=======MENU=======\t\n";
		cout << "1. Nhap DS Lop\n";
		cout << "2. Xuat DS Lop\n";
		cout << "3. Nhap DS Lop tu file\n";
		cout << "4. Dem tong so luong sv khoa\n";
		cout << "5. Dem tong so luong lop khoa\n";
		cout << "6. Xoa 1 lop\n";
		cout << "7. Xoa 1 lop thuoc khoa\n";
		cout << "0. Thoat\n";
		cout << "Lua chon: ";cin >> chon; cin.ignore();
		switch (chon) {
		case 1 :
			nhapDSlop(ds1);
			break;
		case 2:
			xuatDSlop(ds1);
			break;
		case 3:
			docFile(ds1);
			break;
		case 4:
			cout << "Nhap ten khoa: ";
			getline(cin, s1);
			demSV(ds1,s1);
			break;
		case 5:
			cout << "Nhap ten khoa: ";
			getline(cin, s2);
			demLop(ds1,s2);
			break;
		case 6:
			xoa1lop(ds1);
			break;
		case 7:
			cout << "Nhap ten khoa: ";
			getline(cin, s3);
			xoaLopKhoa(ds1,s3);
			break;
		}
	} while (chon != 0);
	del(ds1);
	system("pause");
	return 0;
}


