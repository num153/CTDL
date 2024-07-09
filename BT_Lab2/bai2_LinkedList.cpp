#include <iostream>
using namespace std;
/*========DINH NGHIA NODE========*/
struct Node {
	int data;
	Node *next;
};
void init(Node *&head) {
	head = NULL;
}
Node *createNode(int x) {
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void free(Node* head) {
	delete head;
	head = nullptr;
}
bool isEmpty(Node*head) {
	if (head == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}
/*========THEM XOA========*/
void addFirst(Node *&head, int val) {
	Node *p = createNode(val);
	p->next = head;
	head = p;
}
//void delLast(Node*&head) {
//	Node *p = head;
//	while (!isEmpty && p->next!=NULL)
//	{
//		p = p->next;
//	}
//	if (p->next == NULL) {
//		delete p;
//		p = nullptr;
//		return;
//	}
//}
void delFirst(Node *&head) {
	Node *p = head;
	if (!isEmpty(p)) {
		head = p->next;
		p->next = NULL;
		delete p;
	}
}
/*========DUYET XUAT========*/
void xuatNode(Node*head) {
	Node* flag = head;
	while (flag != NULL) {
		cout << flag->data << "\t";
		flag = flag->next;
	}
}
Node* searchNode(Node*head, int x) {
	Node *p = head;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	return p;
}

int main() {
	Node *head;
	init(head);
	addFirst(head, 10);
	addFirst(head, 20);
	xuatNode(head);
	Node*search = searchNode(head, 20);
	cout << "Vi tri cua 20: " << search << endl;
	delLast(head);
	xuatNode(head);
	free(head);
	system("pause");
	return 0;
}
//Quản lý một danh sách có số phần tử khá lớn, biến động.Mỗi phần tử có kiểu int.
//(Dùng cấu trúc Danh sách liên kết)

//g.Viết thủ tục thêm một phần tử vào cuối danh sách.
//h.Viết thủ tục xoá phần tử cuối danh sách.
//i.Viết thủ tục tìm một phần tử trong danh sách.Nếu tìm thấy, hãy xoá phần tử này.
//j.Từ danh sách trên chuyển thành danh sách có thứ tự. (*)
