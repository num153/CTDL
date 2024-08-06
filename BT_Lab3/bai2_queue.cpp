#include <iostream>
using namespace std;

#define MAX 100

void init(int a[], int& front, int& rear) {
	front = -1;
	rear = -1;
}

bool isEmpty(int front, int rear) {
	return front == -1;
}

bool isFull(int front, int rear) {
	return rear - front == MAX - 1;
}

int push(int a[], int& front, int& rear, int x) {
	if (isFull(front,rear))//Mang bi day
		return 0;
	else {
		if (isEmpty(front,rear))
			front = 0;
		if (rear == MAX - 1) { //Mang bi tran
			for (int i = front;i <= rear;i++) {
				a[i - front] = a[i];
			}
			rear = MAX - 1 - front;//Cap nhat lai rear sau khi doi hang doi
			front = 0;//Cap nhat lai front sau khi doi hang doi
		}
		a[++rear] = x;
		return 1;
	}
}

int pop(int a[], int& front, int& rear, int& x) {
	if (isEmpty(front,rear))
		return 0;
	else {
		x = a[front++];
		if (front > rear) { //Hang doi co 1 phan tu sau khi lay ra se cap nhat lai front rear
			front = -1;
			rear = -1;
		}
		return 1;
	}
}

void xuat(int a[], int front, int rear)
{
	if (isEmpty(front,rear))
		cout << "Queue dang rong" << endl;
	else {
		cout << "Phan tu trong queue: ";
		for (int i = front;i <= rear;i++)
		{
			cout << a[i] << " ";
		}
	}
	
}

int main()
{
	int a[MAX];
	int x, front, rear, flag=false;
	int choice;
	do {
		cout << "==========MENU==========" << endl;
		cout << "1.Khoi tao queue" << endl;
		cout << "2.Them phan tu vao queue" << endl;
		cout << "3.Xoa phan tu trong queue" << endl;
		cout << "4.Hien thi cac phan tu trong queue" << endl;
		cout << "0.Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch (choice) {
		case 1:
			init(a, front, rear);
			cout << "Khoi tao queue thanh cong" << endl;
			flag = true;
			break;
		case 2:
			if (flag) {
				cout << "Nhap phan tu can them: ";
				cin >> x;
				if (push(a, front, rear, x))//neu ham push tra ve 1 thi chay
					cout << "Them thanh cong" << endl;
				else
					cout << "Hang doi khong the them" << endl;
			}
			else
				cout << "Vui long khoi tao queue" << endl;
			break;
		case 3:
			if (flag) {
				if (pop(a, front, rear, x))
					cout << "Gia tri vua lay ra la: " << x << endl;
				else
					cout << "Khong lay duoc phan tu" << endl;
			}
			else
				cout << "Vui long khoi tao queue" << endl;
			break;
		case 4:
			xuat(a, front, rear);
			break;
		default:
			break;
		}
	} while (choice != 0);
	system("pause");
	return 0;
}
