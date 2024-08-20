#include <iostream>

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
void init(DoubleLL& ll) {
	ll.head = NULL;
	ll.tail = NULL;
}
bool isEmpty(DoubleLL& ll) {
	return ll.head == NULL;
}
Node* createNode(int val) {
	Node* p = new Node;
	p->data = val;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void addFirst(DoubleLL& ll, int val) {
	Node* p = createNode(val);
	if (isEmpty(ll)) {//neu list rong thi cho head vao tail vao phan tu p luon
		ll.head = ll.tail = p;
	}
	else
	{
		p->next = ll.head;
		ll.head->prev = p;
		ll.head = p;
	}
}
void addLast(DoubleLL &ll, int val) {
	Node* p = createNode(val);
	if (isEmpty(ll)) {//neu list rong thi cho head vao tail vao phan tu p luon
		ll.head = ll.tail = p;
	}
	else
	{
		p->prev = ll.tail;
		ll.tail->next = p;
		ll.tail = p;
	}
}
void delFirst(DoubleLL &ll) {
	if (!isEmpty(ll)) {
		Node *temp = ll.head;
		if (temp->next == NULL) {
			ll.head = NULL;
			ll.tail = NULL;
		}
		else
		{
			ll.head = temp->next;
			temp->next->prev = NULL;
			temp->next = NULL;
		}
		delete temp;
	}
}
void output(DoubleLL ll) {
	Node* temp = ll.head;
	while (temp != NULL) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
}
int main(){
	DoubleLL ll1;
	init(ll1);
	addFirst(ll1, 20);
	addFirst(ll1, 50);
	addFirst(ll1, 30);
	addLast(ll1, 999);
	delFirst(ll1);
	output(ll1);
	system("pause");
	return 0;
}

//6. Viết thủ tục xóa phần tử đầu danh sách.
//7. Viết thủ tục xóa phần tử cuối dang sách.
//8. Viết thủ tục tìm một phần tử trong danh sách.Nếu tìm thấy, xóa phần tử này.
//9. Viết thủ tục tìm một phần tử có giá trị bằng với giá trị X hoặc gần nhất và lớn hơn phần tữ
//nhập vào;
//10. Thêm một phần tử đứng trước phần tử tìm thấy.
