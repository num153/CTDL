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
//duyet Node
void xuatNode(Node *head){
  Node *p=head;
  while(p!=NULL){
    cout << p->data << "\t";
    p=p->next;
  }
}
int main() 
{
    Node *head;
    init(head);
    addFirst(head,10);
    addFirst(head,20);
    addFirst(head,30);
    xuatNode(head);
    return 0;
}
