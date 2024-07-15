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
void free(Node*& head) {
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
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
/*========THEM XOA========*/
void addFirst(Node *&head, int val) {
	Node *p = createNode(val);
	p->next = head;
	head = p;
}
void addLast(Node *&head,int val){
  Node*p=createNode(val);
  Node*last=head;
  while(last->next!=NULL){
    last=last->next;
  }
  last->next=p;
}
void delFirst(Node *&head) {
	Node *p = head;
	if (!isEmpty(p)) {
		head = p->next;
		p->next = NULL;
		delete p;
	}
}
void delLast(Node*&head){
  if(head!=NULL){
      Node*last=head;
      Node*prev=NULL;
    //xac dinh con tro last va prev
    while(last->next!=NULL){
    prev=last;
    last=last->next;
    }
    if(prev==NULL){ //Neu node chi co 1 phan tu
    delFirst(head);
    }
    else{
    //con neu hai phan tu thi xoa last
    prev->next=NULL;
    delete last;
    }
  }
}
void findAndDel(Node* &head,int val){
  if(head !=NULL){
    Node *p=head;
    Node *prev=NULL;
    while(p != NULL && p->data != val){ //chu y ktra khi p chay den cuoi co val can tim hay khong
      prev=p;
      p=p->next;
    }
    //kiem tra xem co gia tri can xoa khong
    if (p == NULL) {
            cout << "Gia tri " << val << " khong tim thay trong list." << endl;
            return;
        }
    if(prev == NULL){ //neu Node chi co 1 phan tu
      delFirst(head);
    }
    else{
      prev->next=p->next;
      p->next=NULL;
      delete p;  
    }
  }
}
int main() {
	Node *head;
	init(head);
	addFirst(head, 10);
	addFirst(head, 20);
	addLast(head,99);
	xuatNode(head);
	Node*search = searchNode(head, 20);
	cout << "\nVi tri cua 20: " << search << endl;
  findAndDel(head,100);
	xuatNode(head);
	free(head);
	system("pause");
	return 0;
}

//j.Từ danh sách trên chuyển thành danh sách có thứ tự. (*)
