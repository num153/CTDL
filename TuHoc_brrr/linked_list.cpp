#include <iostream>
using namespace std;

//=========DINH NGHIA NODE=========
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
//=========CAC THAO TAC=========
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
void delFirst(Node* &head){ //chu y truyen tham chieu
  Node *p=head;
  if(p != NULL){
    head=p->next;
    p->next=NULL;
    delete p;
  }
}
void delLast(Node *&head){
  if(head != NULL){
    Node *last=head;
    Node* prev=NULL;
    //xac dinh con tro last va prev
    while(last->next != NULL){
      prev = last;
      last=last->next;
    }
    //xoa
    if(prev == NULL){ //Neu node chi co 1 phan tu
      delFirst(last);
    }
    else{
    prev->next=NULL;
    delete last;
    }
  }
}
void delNode(Node* &head,int val){
  if(head !=NULL){
    Node *p=head;
    Node *prev=NULL;
    while(p->data != val){
      prev=p;
      p=p->next;
    }
    if(prev == NULL){ //neu Node chi co 1 phan tu
      delFirst(p);
    }
    else{
      prev->next=p->next;
      p->next=NULL;
      delete p;  
    }
  }
}
//=========DUYET VA XUAT=========
void xuatNode(Node *head){
  Node *danh_dau=head;
  while(danh_dau!=NULL){
    cout << danh_dau->data << "\t";
    danh_dau=danh_dau->next;
  }
}
//xuat dia chi cua Node
void xuatDiachi(Node*head){
  Node* p=head;
  while(p!=NULL){
    cout << p << "\t";
    p=p->next;
  }
}
//tim kiem
Node* search(Node*head,int x){
  Node* p= head;
  while(p!=NULL && p->data!=x){
    p=p->next;
  }return p;
}
//=========GIAI PHONG NODE=========
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
    cout << "\nDia chi cua cac node: " << endl;
    xuatDiachi(head);
    cout << "\nDia chi cua 30: " << p;
    cout << "\nXoa node dau: ";
    delFirst(head);
    delLast(head);
    delNode(head,20);
    xuatNode(head);
    return 0;
}
