/* 
    ouput: chu y khi duyet khong dung flag-next de so sanh, vi den phan tu cuoi cung no se dung lai (thieu)
*/
#include <iostream>
using namespace std;
/*========DINH NGHIA NODE========*/
struct Node {
	int data;
	Node* next;
};
struct Stack {
	Node* head;
};
void init(Stack& s) {
	s.head = NULL;
}
Node* createStack(int x) {
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void freeStack(Stack&s) {
	while (s.head != NULL) {
		Node* temp = s.head;
		s.head = s.head->next;
		delete temp;
	}
}
bool isEmpty(Stack s) {
	return (s.head == NULL);
}
void outputStack(Stack s) {
	Node* flag = s.head;
	while (flag != NULL) {
		cout << flag->data << "\t";
		flag = flag->next;
	}
}
void outputFirst(Stack s) {
	if (!isEmpty(s)) {
		cout << "Phan tu dau: " << s.head->data << endl;
	}
}
void pushStack(Stack& s, int val) {
	Node* p = createStack(val);
	p->next = s.head;
	s.head = p;
}
void popStack(Stack& s) {
	Node* p = s.head;
	if (!isEmpty(s)) {
		s.head = p->next;
		p->next = NULL;
		delete p;
	}
}
//CHUYEN DOI HE 10 SANG HE 2
void convert10_2(Stack &s,int val) {
		while (val != 0) {
			int x = val % 2;
			pushStack(s, x);
			val = val / 2;
		}
	outputStack(s);
}
int main() {
	Stack s1;
	Stack s2;
	int chon;
	init(s1);
	init(s2);
	cout << "STACK: ";
	pushStack(s1, 20);
	pushStack(s1, 10);
	pushStack(s1, 15);
	pushStack(s1, 40);
	outputStack(s1);
	do {
		cout << "\n\t\t======MENU======\n";
		cout << "\t1.Chi hien thi phan tu dau Stack\n";
		cout << "\t2.Xoa phan tu trong Stack\n";
		cout << "\t3.Hien thi phan tu\n";
		cout << "\t4.Chuyen doi he 10 sang 2\n";
		cout << "\t0.Ket thuc\n";
		cout << "\n\t\t======END======\n";
		cout << "Lua chon: "; cin >> chon;
		switch (chon) {
		case 1:
			outputFirst(s1);
			break;
		case 2:
			popStack(s1);
			break;
		case 3:
			outputStack(s1);
			break;
		case 4:
			convert10_2(s2, 10);
			break;
		}
	} while (chon != 0);
	freeStack(s1);
	system("pause");
	return 0;
}
