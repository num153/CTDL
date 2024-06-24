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
//duyet Node
void xuatNode(Node *head){
  Node *danh_dau=head;
  while(danh_dau!=NULL){
    cout << danh_dau->data << "\t";
    danh_dau=danh_dau->next;
  }
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
    xuatNode(head);
    return 0;
}
