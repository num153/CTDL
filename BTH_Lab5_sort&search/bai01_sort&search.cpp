#include <iostream>
#include <ctime>
using namespace std;
#define MAX 100
void input(int a[], int &n) {
	cout << "So luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}
void randomInput(int a[], int &n) {
	cout << "So luong phan tu: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i]= rand() % 10+1; //1 den 10, gtri trc la so luong, gtri sau la start
	}
}
void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << '\t';
	}
}
void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int pos = i - 1;
		int x = a[i];
		while (pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
void selectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		swap(a[min_index], a[i]);
	}
}
void bubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
			}
		}
	}
}
void interchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void linearSearch(int a[], int n, int &x) {
	cout << "\nGia tri can tim: "; cin >> x;
	int i = 0;
	while (i < n && a[i] != x) {
		i++;
	}
	if (i < n) {
	cout << x << " tai " << " a[" << i << "]\n";
	}
	else
	{
		cout << "khong tim thay \n" << x;
	}
}
void binarySearch(int a[], int n, int &x) {
	cout << "\nGia tri can tim: "; cin >> x;
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == x) {
			cout << x << " tai " << " a[" << mid << "]\n";
		}
		if (x > a[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	if (a[mid] != x) {
		cout << "khong thay\n";
	}
}
int main(){
	int a[MAX];
	int n;
	int pos;
	int chon;
	bool flag = false;
	do {
		cout << "\n=======MENU=======\n";
		cout << "1.Tao mang random\n";
		cout << "2.Tao mang thuong\n";
		cout << "3.Xuat mang\n";
		cout << "4.Selection Sort\n";
		cout << "5.Interchange Sort\n";
		cout << "6.Insertion Sort\n";
		cout << "7.Bubble Sort\n";
		cout << "8.Tim kiem tuan tu\n";
		cout << "9.Tim kiem nhi phan\n";
		cout << "0.Thoat\n";
		cout << "----Chon: "; cin >> chon;
		switch (chon) {
		case 1:
			randomInput(a, n);
			flag = true;
			break;
		case 2:
			input(a, n);
			flag = true;
			break;
		case 3:
			if (flag) {
				output(a, n);
			}
			else
			{
				cout << "Chua co mang";
			}
			break;
		case 4:
			if (flag) {
				selectionSort(a, n);
			}
			else
			{
				cout << "Chua co mang";
			}
			break;
		case 5:
			if (flag) {
				interchangeSort(a, n);
			}
			else
			{
				cout << "Chua co mang";
			}
			break;
		case 6:
			if (flag) {
				insertionSort(a, n);
			}
			else
			{
				cout << "Chua co mang";
			}
			break;
		case 7:
			if (flag) {
				bubbleSort(a, n);
			}
			else
			{
				cout << "\nChua co mang";
			}
			break;
		case 8:
			if (flag) {
				linearSearch(a, n, pos);
			}
			else
			{
				cout << "\nChua co mang";
			}
			break;
		case 9:
			if (flag) {
				selectionSort(a, n);
				output(a, n);
				binarySearch(a, n, pos);
			}
			else
			{
				cout << "\nChua co mang";
			}
			break;
		}
	} while (chon != 0);
	system("pause");
	return 0;
}
