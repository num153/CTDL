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
	if(!isEmpty(ll)){
	    Node* temp = ll.head;
	    if(temp->next == NULL){
	        ll.head = NULL;
	        ll.tail = NULL;
	    }else{
	        ll.head = temp->next;
	        temp->next->prev = NULL;
	        temp->next = NULL;
	    }
	    delete temp;
	}
}
void delLast(DoubleLL &ll){
    if(!isEmpty(ll)){
        Node* temp = ll.tail;
        if(temp->prev == NULL){
            ll.head = NULL;
            ll.tail = NULL;
        }else{
            ll.tail = temp->prev;
            temp->prev->next = NULL;
            temp->prev = NULL;
        }
        delete temp;
    }
}
bool find(int a, int b){
    return a == b;
}
void findAndDel(DoubleLL &ll, int val){
    //phai it nhat mot phan tu
    if(!isEmpty(ll)){
        Node *temp = ll.head;
        while(!find(temp->data,val) && temp != NULL){
            //temp->next != NULL thi o den tail no dung mat tieu
            temp = temp->next;
        }
        if(temp!=NULL){
            //neu val o dau 
            if(temp->prev==NULL){
                delFirst(ll);
            }//neu val o cuoi
            else if(temp->next == NULL){
                delLast(ll);
            }//neu val o chinh giua
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                // temp->next = NULL;
                // temp->prev = NULL; k can thiet lam vi kieu gi cung delete roi
                delete temp;
            }
        }else{
            cout << "Khong tim thay " << val << endl;
        }
        // delete temp; k dc de o day vi da delete temp dau cuoi roi
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
	DoubleLL ls;
	init(ls);
	addFirst(ls, 20);
	addFirst(ls, 50);
	addFirst(ls, 30);
	addLast(ls, 999);
	findAndDel(ls,999);
	output(ls);
	system("pause");
	return 0;
}

//9. Viết thủ tục tìm một phần tử có giá trị bằng với giá trị X hoặc gần nhất và lớn hơn phần tữ
//nhập vào;
//10. Thêm một phần tử đứng trước phần tử tìm thấy.
