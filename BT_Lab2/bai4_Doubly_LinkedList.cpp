/* Bai nay chu y cau truc Find to Del/Add boi vi phai xet vi tri head/tail */
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};
struct DoubleLL {
	Node* head;
	Node* tail;
};
void init(DoubleLL& ls) {
	ls.head = NULL;
	ls.tail = NULL;
}
void free(DoubleLL& ls) {
	while (ls.head != NULL)
	{
		Node* temp = ls.head;
		ls.head = ls.head->next;
		delete temp;
	}
	ls.head = NULL;
	ls.tail = NULL;
}
Node* createNode(int val) {
	Node* p = new Node;
	p->data = val;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void addFirst(DoubleLL& ls, int val) {
	Node* p = createNode(val);
	if (ls.head == NULL) {//neu list rong thi cho head vao tail vao phan tu p luon
		ls.head = ls.tail = p;
	}
	else
	{
		p->next = ls.head;
		ls.head->prev = p;
		ls.head = p;
	}
}
void addLast(DoubleLL& ls, int val) {
	Node* p = createNode(val);
	if (ls.head == NULL) {
		ls.head = ls.tail = p;
	}
	else
	{
		p->prev = ls.tail;
		ls.tail->next = p;
		ls.tail = p;
	}
}
void delFirst(DoubleLL& ls) {
	//list co it nhat mot phan tu
	if (ls.head != NULL) {
		Node* temp = ls.head;
		if (temp->next == NULL) { //neu chi co 1 phan tu
			ls.tail = NULL;
			ls.head = NULL;
		}
		else {
			//co tu 2 phan tu (chu y thu tu cac step keo mat dau)
			ls.head = temp->next;
			temp->next->prev = NULL;
			temp->next = NULL;
		}
		delete temp;
	}
}
void delLast(DoubleLL& ls) {
	if (ls.head != NULL) {
		Node* temp = ls.tail;
		if (temp->prev == NULL) {
			ls.head = NULL;
			ls.tail = NULL;
		}
		else
		{
			ls.tail = temp->prev;
			temp->prev->next = NULL;
			temp->prev = NULL;
		}
		delete temp;
	}
}
void findAndDel(DoubleLL& ls,int val) {
	//kiem tra list co it nhat mot phan tu
	if (ls.head != NULL) {
		Node* temp = ls.head;
		//duyet de tim kiem vi tri val can xoa
		while (temp != NULL && temp->data != val) {
			temp = temp->next;
		}
		//duyet den cuoi va da thay val can xoa
		if (temp != NULL) {
			//kiem tra neu val o dau/cuoi va chinh giua
			if (temp == ls.head) {
				delFirst(ls);
			}
			else if (temp == ls.tail) {
				delLast(ls);
			}
			//val o giua
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
			}
		}
		//neu duyet den cuoi ma khong co val can xoa (temp==NULL)
		else{
			cout << "Gia tri " << val << " khong co trong list\n";
			return;
		}
	}
}
void addAfter(DoubleLL& ls, int vt, int val) {
	Node* temp = ls.head;
	//duyet vt 
	while (temp != NULL && temp->data != vt) {
		temp = temp->next;
	}
	//temp chay den cuoi list va da tim thay vt 
	if (temp != NULL) {
		//neu temp o head
		if (temp == ls.head) {
			addFirst(ls, val);
		}
		//neu temp o tail
		else if (temp == ls.tail) {
			addLast(ls, val);
		}
		//neu temp o giua
		else {
		Node* p = createNode(val);
		p->next = temp->next;
		temp->next->prev = p;
		temp->next = p;
		p->prev = temp;
		}
	}
	//neu duyet den cuoi ma khong co vt can chen (temp==NULL)
	else{
		cout << "Gia tri " << vt << " khong co trong list\n";
		return;
	}
}
void xuatNodeheadTotail(DoubleLL ls) {
	Node* temp = ls.head;
	while (temp != NULL) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
}
void xuatNodetailTohead(DoubleLL ls) {
	Node* temp = ls.tail;
	while (temp != NULL) {
		cout << temp->data << "\t";
		temp = temp->prev;
	}
}

int main() {
	DoubleLL ls1;
	init(ls1);
	addFirst(ls1, 10);
	addFirst(ls1, 40);
	addLast(ls1, 99);
	findAndDel(ls1, 10);
	addAfter(ls1, 77, 1000);
	xuatNodeheadTotail(ls1);
	free(ls1);
	system("pause");
	return 0;
}

//i.Viết thủ tục tìm một phần tử có giá trị bằng với giá trị x hoặc gần nhất và lớn hơn phần
//tử x nhập vào; Thêm một phần tử trước phần tử tìm thấy
