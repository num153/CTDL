#include <iostream>
using namespace std;

#define MAX 100

struct List {
	int n;
	int arr[MAX];
};
void nhapList(List &ds) {
	cout << "Nhap so luong phan tu: "; cin >> ds.n;
	for (int i = 0; i < ds.n; i++) {
		cout << "a[" << i << "]: ";
		cin >> ds.arr[i];
	}
}
void xuatList(List ds) {
	for (int i = 0; i < ds.n; i++) {
		cout << ds.arr[i] << "\t";
	}
}
int searchList(List ds, int &x) {
	int i = 0;
	while (i<ds.n && ds.arr[i] != x)
	{
		i++;
	}
	if (i == ds.n) { //i den cuoi mang ma k co gia tri can tim
		return -1;
	}
	else
	{
		return i;
	}
}
void addLast(List &ds, int val) {
	if (ds.n < MAX) {
		ds.arr[ds.n] = val;
		ds.n++;
	}
	else
	{
		cout << "Khong the them\n";
	}
}
void removeLast(List &ds) {
	if (ds.n > 0) {
		ds.n--;
	}
	else
	{
		cout << "Danh sach rong xoa kieu gi\n";
	}
}
void addIndex(List &ds,int &vt, int &val) {
	//chay tu cuoi & dun truoc ra sau
	if (vt >= 0 && vt <= ds.n) {
		for (int i = ds.n; i > vt; i--) {
			ds.arr[i] = ds.arr[i - 1];
		}
		ds.arr[vt] = val;
		ds.n++;
	}
	else
	{
		cout << "Vi tri khong hop le\n";
	}
}
void removeIndex(List &ds,int &vt) {
	if (vt>=0 && vt<ds.n) {
		for (int i = vt; i < ds.n; i++) {
			ds.arr[i] = ds.arr[i + 1];
		}
		ds.n--;
	}
	else
	{
		cout << "Vi tri khong hop le\n";
	}
}
void removeValue(List &ds, int &val) {
	int vt;
	if (searchList(ds,val)!=-1) {
		vt = searchList(ds, val);
		cout << "Vi tri cua " << val << " la: " << vt << endl;
		for (int i = vt; i < ds.n; i++) {
			ds.arr[i] = ds.arr[i + 1];
		}
		ds.n--;
	}
	else
	{
		cout << "Khong co phan tu can xoa\n";
	}
}
int main() {
	List ds1; int x;
	int vt1, val1, vt2;
	int chon;
	do {
		cout << "\n=======J97 Skibidi Dom Dom=======\n";
		cout << "1.Nhap ds\n";
		cout << "2.Xuat ds\n";
		cout << "3.Tim phan tu\n";
		cout << "4.Them phan tu cuoi\n";
		cout << "5.Xoa phan tu cuoi\n";
		cout << "6.Them phan tu tai vi tri\n";
		cout << "7.Xoa phan tu tai vi tri\n";
		cout << "8.Tim kiem va xoa phan tu\n";
		cout << "0.Thoat\n";
		cout << "Lua chon: "; cin >> chon;
		switch (chon) {
		case 1:
			nhapList(ds1);
			break;
		case 2:
			xuatList(ds1);
			break;
		case 3:
			cout << "Gia tri can tim: "; cin >> x;
			if (searchList(ds1, x) != -1) {
				cout << "Vi tri cua " << x << " la: " << searchList(ds1, x) << endl;
			}
			else
			{
				cout << "Khong co gia tri can tim\n";
			}
			break;
		case 4:
			addLast(ds1,999);
			break;
		case 5:
			removeLast(ds1);
			break;
		case 6:
			cout << "Nhap vi tri can chen: "; cin >> vt1;
			cout << "Nhap gia tri can chen: "; cin >> val1;
			addIndex(ds1, vt1, val1);
			break;
		case 7:
			cout << "Nhap vi tri can xoa: "; cin >> vt2;
			removeIndex(ds1,vt2);
			break;
		case 8:
			int val3;
			cout << "Nhap gia tri can tim va xoa: "; cin >> val3;
			removeValue(ds1, val3);
			xuatList(ds1);
			break;
		}
	} while (chon != 0);
	system("pause");
	return 0;
}
