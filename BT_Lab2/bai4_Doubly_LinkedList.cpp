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
	addLast(ls1, 99);
	delFirst(ls1);
	xuatNodeheadTotail(ls1);
	system("pause");
	return 0;
}

//f.Viết thủ tục xoá phần tử đầu danh sách
//g.Viết thủ tục xoá phần tử cuối danh sách
//h.Viết thủ tục tìm một phần tử trong danh sách.Nếu tìm thấy, xoá phần tử này
//i.Viết thủ tục tìm một phần tử có giá trị bằng với giá trị x hoặc gần nhất và lớn hơn phần
//tử x nhập vào; Thêm một phần tử trước phần tử tìm thấy
