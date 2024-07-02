#include <iostream>
using namespace std;

//dinh nghia cau truc node
struct Node{
  int data;
  Node *next; //con tro link toi node tiep theo
};

//tao con tro head (khoi dong ds)
void init(Node *&head){
  head=NULL;
}

//tao node 
Node* createNode(int x){
  Node *p= new Node;
  p->data= x;
  p->next=NULL;
  return p;
}

void addFirst(Node *&head, int x){
  Node *p=createNode(x);
  p->next=head;
  head=p;
}
void addLast(Node *&head, int x){
  Node *p=createNode(x);
  //xac dinh vi tri con tro last 
  Node *last=head;
  while(last->next!=NULL){
    last=last->next;
  }
  //chen vao cuoi
  last->next=p;
}
void addAfter(Node*head,int vt,int x){
  Node*p=createNode(x);
  //tim node co gia tri vt
  Node*q=head;
  while(q!=NULL&&q->data!=vt){
    q=q->next;
  }
  if(q!=NULL){
    p->next=q->next;
    q->next=p;
  }
}
//duyet Node
void xuatNode(Node *head){
  Node *danh_dau=head;
  while(danh_dau!=NULL){
    cout << danh_dau->data << "\t";
    danh_dau=danh_dau->next;
  }
}
//tim kiem
Node* search(Node*head,int x){
  Node* p= head;
  while(p!=NULL && p->data!=x){
    p=p->next;
  }return p;
}
void del(Node* n){
  delete n;
  n=nullptr;
}
int main() 
{
    Node *head;
    init(head);
    addFirst(head,10);
    addFirst(head,20);
    addFirst(head,30);
    addLast(head,5);
    addAfter(head,30,400);
    xuatNode(head);
    Node *p = search(head,30);
    cout << "\nVi tri cua 30: " << p;
    return 0;
}
